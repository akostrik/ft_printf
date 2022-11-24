/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/21 15:29:09 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Concatenate dst + src
// Appends at most n-strlen(dst)-1 bytes
// NUL-terminates the result as long as there is at least 1 byte free in dst
// A byte for the NUL should be included in n
// Takes the full size of the buffer (not just the length)
// src and dst must be NUL-terminated (true “C” strings)
// Returns the total length of the string it tried to create =
// the initial dst-length + src-length (=> truncation detection simple)
// Replacements for strncat (more consistent, and less error prone)
// возвращает суммарную длину строк по адресам src и dst
// Возвращаемое значение не зависит от того, удалось ли скопировать строку
// полностью => определить что буфер назначения мал для копируемой строки

#include "libft.h"

static size_t	calc_nb_chars_to_append_without_zero(char *dst, \
	const char *src, size_t n)
{
	size_t	src_length;
	size_t	dst_initial_len;

	dst_initial_len = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (dst_initial_len + src_length + 1 <= n)
		return (src_length);
	if (dst_initial_len + 1 < n)
		return (n - dst_initial_len - 1);
	return (0);
}

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	src_length;
	size_t	dst_initial_len;
	size_t	nb_chars_to_append;

	src_length = ft_strlen(src);
	dst_initial_len = ft_strlen(dst);
	nb_chars_to_append = calc_nb_chars_to_append_without_zero(dst, src, n);
	i = 0;
	while (i < nb_chars_to_append)
	{
		dst[dst_initial_len + i] = src[i];
		i++;
	}
	dst[dst_initial_len + i] = '\0';
	if (dst_initial_len <= n)
		return (dst_initial_len + src_length);
	return (src_length + n);
}
