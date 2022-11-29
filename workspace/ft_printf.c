/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:46:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/29 14:10:17 by akostrik         ###   ########.fr       */
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

static char	to_char(unsigned long pp)
{
	if (pp % 16 <= 9)
		return (pp % 16 + '0');
	return (pp % 16 - 10 + 'a');
}

static void	putpointer_fd(void *p, int fd)
{
	ft_putchar_fd('0',fd);	
	ft_putchar_fd('x',fd);
	ft_putchar_fd(to_char(((unsigned long)p & 0xf00000000000) >> 44),fd);
	ft_putchar_fd(to_char(((unsigned long)p & 0x0f0000000000) >> 40),fd);
	ft_putchar_fd(to_char(((unsigned long)p & 0x00f000000000) >> 36),fd);
	ft_putchar_fd(to_char(((unsigned long)p & 0x000f00000000) >> 32),fd);
	ft_putchar_fd(to_char(((unsigned long)p & 0x0000f0000000) >> 28),fd);
	ft_putchar_fd(to_char(((unsigned long)p & 0x00000f000000) >> 24),fd);
	ft_putchar_fd(to_char(((unsigned long)p & 0x000000f00000) >> 20),fd);
	ft_putchar_fd(to_char(((unsigned long)p & 0x0000000f0000) >> 16),fd);
	ft_putchar_fd(to_char(((unsigned long)p & 0x00000000f000) >> 12),fd);
	ft_putchar_fd(to_char(((unsigned long)p & 0x000000000f00) >> 8),fd);
	ft_putchar_fd(to_char(((unsigned long)p & 0x0000000000f0) >> 4),fd);
	ft_putchar_fd(to_char(((unsigned long)p & 0x00000000000f)),fd);
}

static void	put_unsigned_int_fd_rec(unsigned int n, int fd)
{
	char	c;

	if (n == 0)
		return ;
	put_unsigned_int_fd_rec(n / 10, fd);
	c = n - (n / 10) * 10 + '0';
	write(fd, &c, 1);
}

static void	put_unsigned_int_fd(unsigned int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	put_unsigned_int_fd_rec(n, fd);
}

int	ft_printf(const char *s, ...)
{
	va_list list_args;
	size_t	i;

	va_start(list_args, s);
	i = 0;
	while (i < ft_strlen((char *)s))
	{
		if (ft_strncmp(&s[i], "%s", 2) == 0)
			ft_putstr_fd(va_arg(list_args, char*), 1);
		else if (ft_strncmp(&s[i], "%c", 2) == 0)
			ft_putchar_fd(va_arg(list_args, int), 1);
		else if (ft_strncmp(&s[i], "%p", 2) == 0)
			putpointer_fd(va_arg(list_args, void*), 1);
		else if (ft_strncmp(&s[i], "%d", 2) == 0)
			ft_putnbr_fd(va_arg(list_args, int), 1);
		else if (ft_strncmp(&s[i], "%i", 2) == 0)
			ft_putnbr_fd(va_arg(list_args, int), 1);
		else if (ft_strncmp(&s[i], "%u", 2) == 0)
			put_unsigned_int_fd(va_arg(list_args, unsigned int), 1);
		else if (ft_strncmp(&s[i], "%x", 2) == 0)
			put_int_base_16_fd(va_arg(list_args, unsigned int), 1, 'x');
		else if (ft_strncmp(&s[i], "%X", 2) == 0)
			put_int_base_16_fd(va_arg(list_args, unsigned int), 1, 'X');
		else if (ft_strncmp(&s[i], "%%", 2) == 0)
			ft_putchar_fd('%', 1);
		else
			ft_putchar_fd(s[i--], 1);
		i += 2;
	}
	va_end(list_args);
	return (1);
}
