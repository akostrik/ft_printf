/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_functons.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:17:39 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/30 11:45:08 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	putchar_(char c, int fd)
{
	return (write(fd, &c, 1));
}

ssize_t	putstr(char *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}

unsigned long	pow_(unsigned long n, unsigned long k)
{
	unsigned int	i;
	unsigned long	res;

	i = 0;
	res = 1;
	while (i < k)
	{
		res *= n;
		i++;
	}
	return (res);
}

int	calc_nb_digits(unsigned long n, size_t base)
{
	size_t	i;

	i = 0;
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}
