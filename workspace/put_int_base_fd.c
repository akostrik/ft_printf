/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int_base_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:51:51 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/29 21:59:23 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	putchar_(char c, int fd)
{
	return (write(fd, &c, 1));
}

ssize_t putstr(char *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}

static unsigned int	my_pow(unsigned int n, unsigned int k)
{
	unsigned int	i;
	unsigned int	res;

	i = 0;
	res = 1;
	while (i < k)
	{
		res *= n;
		i++;
	}
	return (res);
}

ssize_t	put_unsigned_int_base(unsigned int n, size_t base, int fd, char x)
{
	size_t	i;
	size_t	k;
	size_t	nb_digits;
	int		digit;
	ssize_t	ret;

	//printf("\nput_unsigned_int_base %d %zu\n",n,base);
	if (n == 0)
		return (putchar_('0', fd));
	i = 0;
	k = n;
	while (k > 0)
	{
		k = k / base;
		i++;
	}
	nb_digits = i;
	i = 0;
	ret = 0;
	while (i < nb_digits)
	{
		//printf("\ndigit = %d / %d\n",n,my_pow(base, nb_digits - i - 1));
		digit = n / my_pow(base, nb_digits - i - 1);
		//printf("digit = %d\n",digit);
		if (digit % base <= 9)
			ret += putchar_(digit % base + '0', 1);
		else if (x == 'x')
			ret += putchar_(digit % base - 10 + 'a', 1);
		else if (x == 'X')
			ret += putchar_(digit % base - 10 + 'A', 1);
		n = n % my_pow(base, nb_digits - i - 1);
		i++;
	}
	//printf("\nret = %zd\n",ret);
	return (ret);
}

ssize_t	put_int_base_10(int n, int fd)
{
	size_t ret;

	if (n == 0)
		return (putchar_('0', fd));
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
	ret += put_unsigned_int_base((unsigned int)n, 10, 1, 0);
	return (ret);
}

static char	last_to_char(unsigned long pp)
{
	if (pp % 16 <= 9)
		return (pp % 16 + '0');
	return (pp % 16 - 10 + 'a');
}

ssize_t put_pointer(void *p, int fd) // put_unsigned_int_base_fd
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
}
