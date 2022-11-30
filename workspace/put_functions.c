/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:51:51 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/30 11:44:56 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	put_uns_long_base(unsigned long n, size_t base, char uppercase, int fd)
{
	size_t	i;
	size_t	nb_digits;
	int		digit_as_int_10;
	char	digit_as_char_base;
	ssize_t	ret;

	if (n == 0)
		return (putchar_('0', fd));
	nb_digits = calc_nb_digits(n, base);
	i = 0;
	ret = 0;
	while (i < nb_digits)
	{
		digit_as_int_10 = n / pow_(base, nb_digits - i - 1);
		if (digit_as_int_10 % base <= 9)
			ret += putchar_(digit_as_int_10 % base + '0', 1);
		else
		{
			digit_as_char_base = digit_as_int_10 % base - 10 + 'a';
			if (uppercase == 'X')
				digit_as_char_base = ft_toupper(digit_as_char_base);
			ret += putchar_(digit_as_char_base, 1);
		}
		n = n % pow_(base, nb_digits - i - 1);
		i++;
	}
	return (ret);
}

ssize_t	put_int_base_10(int n, int fd)
{
	ssize_t	ret;

	if (n == INT_MIN)
		return (putstr("-2147483648", 1));
	ret = 0;
	if (n < 0)
	{
		if (putchar_('-', fd) == -1)
			return (-1);
		n = -n;
		ret ++;
	}
	ret += put_uns_long_base((unsigned int)n, 10, 'x', fd);
	return (ret);
}

ssize_t	put_pointer(void *p, int fd)
{
	ssize_t	ret1;
	ssize_t	ret2;

	ret1 = putstr("0x", fd);
	if (ret1 == -1)
		return (-1);
	ret2 = put_uns_long_base((unsigned long)(p), 16, 'x', fd);
	if (ret2 == -1)
		return (-1);
	return (ret1 + ret2);
}

/*
static char	last_to_char(unsigned long pp)
{
	if (pp % 16 <= 9)
		return (pp % 16 + '0');
	return (pp % 16 - 10 + 'a');
}

ssize_t put_pointer(void *p, int fd) 
{
	ssize_t	ret;

	ret = 0;
	ret += putchar_('0', fd);
	ret += putchar_('x', fd);
	ret += putchar_(last_to_char(((unsigned long)p & 0xf00000000000) >> 44), fd);
	ret += putchar_(last_to_char(((unsigned long)p & 0x0f0000000000) >> 40), fd);
	ret += putchar_(last_to_char(((unsigned long)p & 0x00f000000000) >> 36), fd);
	ret += putchar_(last_to_char(((unsigned long)p & 0x000f00000000) >> 32), fd);
	ret += putchar_(last_to_char(((unsigned long)p & 0x0000f0000000) >> 28), fd);
	ret += putchar_(last_to_char(((unsigned long)p & 0x00000f000000) >> 24), fd);
	ret += putchar_(last_to_char(((unsigned long)p & 0x000000f00000) >> 20), fd);
	ret += putchar_(last_to_char(((unsigned long)p & 0x0000000f0000) >> 16), fd);
	ret += putchar_(last_to_char(((unsigned long)p & 0x00000000f000) >> 12), fd);
	ret += putchar_(last_to_char(((unsigned long)p & 0x000000000f00) >> 8), fd);
	ret += putchar_(last_to_char(((unsigned long)p & 0x0000000000f0) >> 4), fd);
	ret += putchar_(last_to_char(((unsigned long)p & 0x00000000000f)), fd);
	return (ret);
}*/
