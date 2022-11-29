/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:46:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/29 19:04:44 by akostrik         ###   ########.fr       */
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

// a pointer to any object type may be converted to void*
// void* is useful in function parameters to allow passing values of any type
// void* can't be dereferenced (it would give a value of type void)
// void* : pointer arithmetic is not possible

static char	last_to_char(unsigned long pp)
{
	if (pp % 16 <= 9)
		return (pp % 16 + '0');
	return (pp % 16 - 10 + 'a');
}

static void	putpointer_fd(void *p, int fd)
{
	ft_putchar_fd('0', fd);
	ft_putchar_fd('x', fd);
	ft_putchar_fd(last_to_char(((unsigned long)p & 0xf00000000000) >> 44), fd);
	ft_putchar_fd(last_to_char(((unsigned long)p & 0x0f0000000000) >> 40), fd);
	ft_putchar_fd(last_to_char(((unsigned long)p & 0x00f000000000) >> 36), fd);
	ft_putchar_fd(last_to_char(((unsigned long)p & 0x000f00000000) >> 32), fd);
	ft_putchar_fd(last_to_char(((unsigned long)p & 0x0000f0000000) >> 28), fd);
	ft_putchar_fd(last_to_char(((unsigned long)p & 0x00000f000000) >> 24), fd);
	ft_putchar_fd(last_to_char(((unsigned long)p & 0x000000f00000) >> 20), fd);
	ft_putchar_fd(last_to_char(((unsigned long)p & 0x0000000f0000) >> 16), fd);
	ft_putchar_fd(last_to_char(((unsigned long)p & 0x00000000f000) >> 12), fd);
	ft_putchar_fd(last_to_char(((unsigned long)p & 0x000000000f00) >> 8), fd);
	ft_putchar_fd(last_to_char(((unsigned long)p & 0x0000000000f0) >> 4), fd);
	ft_putchar_fd(last_to_char(((unsigned long)p & 0x00000000000f)), fd);
}

static void	put_unsigned_int_fd(unsigned int n, int fd, int first_call)
{
	char	c;

	if (n == 0 && first_call == 1)
		write(fd, "0", 1);
	if (n == 0)
		return ;
	put_unsigned_int_fd(n / 10, fd, 0);
	c = n - (n / 10) * 10 + '0';
	write(fd, &c, 1);
}

static size_t	avance(const char *s)
{
	if (ft_strncmp(s, "%s", 2) == 0)
		return (2);
	else if (ft_strncmp(s, "%c", 2) == 0)
		return (2);
	else if (ft_strncmp(s, "%p", 2) == 0)
		return (2);
	else if (!ft_strncmp(s, "%d", 2) || !ft_strncmp(s, "%i", 2))
		return (2);
	else if (ft_strncmp(s, "%u", 2) == 0)
		return (2);
	else if (!ft_strncmp(s, "%x", 2) || !ft_strncmp(s, "%X", 2))
		return (2);
	else if (ft_strncmp(s, "%%", 2) == 0)
		return (2);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	list_args;
	size_t	i;

	va_start(list_args, s);
	i = 0;
	while (i < ft_strlen((char *)s))
	{
		if (ft_strncmp(&s[i], "%s", 2) == 0)
			ft_putstr_fd(va_arg(list_args, char *), 1);
		else if (ft_strncmp(&s[i], "%c", 2) == 0)
			ft_putchar_fd(va_arg(list_args, int), 1);
		else if (ft_strncmp(&s[i], "%p", 2) == 0)
			putpointer_fd(va_arg(list_args, void *), 1);
		else if (!ft_strncmp(&s[i], "%d", 2) || !ft_strncmp(&s[i], "%i", 2))
			ft_putnbr_fd(va_arg(list_args, int), 1);
		else if (ft_strncmp(&s[i], "%u", 2) == 0)
			put_unsigned_int_fd(va_arg(list_args, unsigned int), 1, 1);
		else if (!ft_strncmp(&s[i], "%x", 2) || !ft_strncmp(&s[i], "%X", 2))
			put_int_base_16_fd(va_arg(list_args, unsigned int), 1, s[i + 1]);
		else
			ft_putchar_fd(s[i], 1);
		i = i + avance(&s[i]);
	}
	va_end(list_args);
	return (1);
}
