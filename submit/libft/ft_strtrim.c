/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:12:27 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/16 15:20:51 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s1: La chaîne de caractères à trimmer
// set: Le set de référence de caractères à trimmer
// Retourns La chaîne de caractères trimmée, NULL si l’allocation échoue
// fonc. authorisées : malloc
// Alloue (avec malloc(3)) et retourne une copie de la chaîne ’s1’, sans les 
// caractères spécifiés
// dans ’set’ au début et à la fin de la chaîne de caractères

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static int	to_trim(char c, char const *set)
{
	size_t	i;

	if (c == '\0')
		return (1);
	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*null_terminated(char *str, size_t len)
{
	str[len] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*new_str;
	size_t	new_str_start;
	size_t	new_str_end;

	new_str_start = 0;
	while (to_trim(s1[new_str_start], set) == 1 && s1[new_str_start] != '\0')
		new_str_start++;
	new_str_end = 0;
	while (s1[new_str_end] != '\0')
		new_str_end++;
	while (to_trim(s1[new_str_end], set) == 1 && new_str_end > 0)
		new_str_end--;
	if (new_str_start > new_str_end)
		return ("");
	new_str = (char *)malloc(new_str_end - new_str_start + 2);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < new_str_end - new_str_start + 1)
	{
		new_str[i] = s1[new_str_start + i];
		i++;
	}
	return (null_terminated(new_str, i));
}
