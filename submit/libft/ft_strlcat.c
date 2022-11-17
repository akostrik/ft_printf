/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/14 15:48:23 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Concatenate dst + src
// Appends at most n-strlen(dst)-1 bytes
// NUL-terminates the result as long as there is at least 1 byte free in dst
// A byte for the NUL should be included in n
// Takes the full size of the buffer (not just the length)
// src and dst must be NUL-terminated (true “C” strings)
// Returns the total length of the string it tried to create = 
// the initial dst-length + src-length (to make truncation detection simple)
// Replacements for strncat (more consistent, and less error prone)
// Returns ...

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	id;
	size_t	is;
	size_t	dst_initial_length;

	id = 0;
	is = 0;
	while (dst[id] != '\0')
		id++;
	dst_initial_length = id;
	while (is < (int)n - dst_initial_length - 1)
	{
		dst[id] = src[is];
		if (src[is] == '\0')
			break ;
		is++;
		id++;
	}
	dst[id + is] = '\0';
	is = 0;
	while (src[is] != '\0')
		is++;
	if (dst_initial_length + n < dst_initial_length + is)
		return (dst_initial_length + n);
	return (dst_initial_length + is);
}
