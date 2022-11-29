/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int_base_16_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:51:51 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/29 18:24:29 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	calculate_nb_bytes(unsigned int n)
{
	size_t	i;

	i = 0;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static int	my_pow(unsigned int n, size_t k)
{
	size_t			i;
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

void	put_int_base_16_fd(unsigned int n, int fd, char x)
{
	size_t	i;
	size_t	nb_bytes;
	int		digit;

	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	nb_bytes = calculate_nb_bytes(n);
	i = 0;
	while (i < nb_bytes)
	{
		digit = n / my_pow(16, nb_bytes - i - 1);
		if (digit % 16 <= 9)
			ft_putchar_fd(digit % 16 + '0', 1);
		else if (x == 'x')
			ft_putchar_fd(digit % 16 - 10 + 'a', 1);
		else if (x == 'X')
			ft_putchar_fd(digit % 16 - 10 + 'A', 1);
		n = n % my_pow(16, nb_bytes - i - 1);
		i++;
	}
}
