/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:46:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/29 23:48:07 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Une bibliothèque qui contient ft_printf(), imitant printf() originale
// Contrairement à printf(), ne pas gérer de buffer
// %c caractère
// %s chaîne (telle que définie par la convention C)
// %p L’argument de pointeur void * doit être affiché en hexadécimal
// %d nombre décimal (base 10)
// %i entier en base 10
// %u nombre décimal non signé (base 10)
// %x nombre en hexadécimal (base 16) avec des lettres minuscules
// %X nombre en hexadécimal (base 16) avec des lettres majuscules
// %% %
// rendu : Makefile, *.h, */*.h, *.c, */*.c
// malloc free write libft
// обязательный аргумент – первое переданное число, если его не передавать, то
// не сможем найти адрес, по которому размещаются переменные в стеке
// Upon successful return, returns the number of characters printed 
// (excluding the null byte used to end output to strings)

// a pointer to any object type may be converted to void*
// void* is useful in function parameters to allow passing values of any type
// void* can't be dereferenced (it would give a value of type void)
// void* : pointer arithmetic is not possible

// size_t
// a count of bytes
// the result of the sizeof operator
// C standard: unsigned int [0, SIZE_MAX]
// POSIX: the implementation supports one or more programming environments where 
// the width of size_t is no greater than the width of the type long.
// %zu %zx

// ssize_t
// a count of bytes / an error indication
// POSIX: a signed integer [-1, SSIZE_MAX], 
// %zd %zi

static int is_conversion(const char *s)
{
	if (!ft_strncmp(s, "%s", 2))
		return (1);
	else if (!ft_strncmp(s, "%c", 2))
		return (1);
	else if (!ft_strncmp(s, "%p", 2))
		return (1);
	else if (!ft_strncmp(s, "%d", 2) || !ft_strncmp(s, "%i", 2))
		return (1);
	else if (!ft_strncmp(s, "%u", 2))
		return (1);
	else if (!ft_strncmp(s, "%x", 2) || !ft_strncmp(s, "%X", 2))
		return (1);
	else if (!ft_strncmp(s, "%%", 2))
		return (1);
	return (0);
}

static ssize_t put_conversion(const char *s, va_list	list_args, int fd)
{
	size_t ret1;
	size_t ret2;

	if (ft_strncmp(s, "%s", 2) == 0)
		return (putstr(va_arg(list_args, char *), fd));
	if (ft_strncmp(s, "%c", 2) == 0)
		return (putchar_(va_arg(list_args, int), fd));
	if (ft_strncmp(s, "%p", 2) == 0)
	{
		ret1 = putstr("0x", fd);
		if (ret1 == 1)
			return (-1);
		ret2 = put_uns_long_base((unsigned long)(va_arg(list_args, void *)),16,'x',fd);
		if (ret2 == 1)
			return (-1);
		return (ret1 + ret2);
	}
	if (!ft_strncmp(s, "%d", 2) || !ft_strncmp(s, "%i", 2))
		return (put_int_base_10(va_arg(list_args, int), fd));
	if (ft_strncmp(s, "%u", 2) == 0)
		return (put_uns_long_base(va_arg(list_args, unsigned int), 10, 1, fd));
	if (!ft_strncmp(s, "%x", 2) || !ft_strncmp(s, "%X", 2))
		return (put_uns_long_base(va_arg(list_args, unsigned int), 16, s[1], fd));
	if (ft_strncmp(s, "%%", 2) == 0)
		return (putchar_('%', fd));
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	ssize_t	ret;
	va_list	list_args;
	int 	fd;

	fd = 1;
	va_start(list_args, s);
	i = 0;
	ret = 0;
	while (i < ft_strlen((char *)s))
	{
		if (is_conversion(&s[i]) == 1)
		{
			ret += put_conversion(&s[i], list_args, fd);
			i++;
		}
		else
			ret += putchar_(s[i], fd);
		i++;
	}
	va_end(list_args);
	return ((int)ret);
}
