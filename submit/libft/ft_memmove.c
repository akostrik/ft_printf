/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/14 17:45:11 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Copies n bytes from memory area src to memory area dest
// src and dest may overlap: 
// the bytes in src are first copied into a tmp array that does not 
// overlap src or dest, and the bytes are then copied from the tmp array to dest
// Returns a pointer to dest

#include <stddef.h>

static int	src0_inside_src(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 1;
	while (i < n)
	{
		if ((const void *)dest == src + i)
			return (1);
		i++;
	}
	return (0);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (src0_inside_src(dest, src, n) == 1)
	{
		i = n;
		while (1)
		{
			i--;
			*((char *)dest + i) = *((char *)src + i);
			if (i == 0)
				break ;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			*((char *)dest + i) = *((char *)src + i);
			i++;
		}
	}
	return (dest);
}
