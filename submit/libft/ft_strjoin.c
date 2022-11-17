/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:50:57 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/16 14:50:58 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s1: La chaîne de caractères préfixe.
// s2: La chaîne de caractères suffixe.
// Returns La nouvelle chaîne de caractères, NULL si l’allocation échoue
// fonctions autorisées : malloc
// Alloue (avec malloc(3)) et retourne une nouvelle chaîne, résultat de 
// la concaténation de s1 et s2

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_length;
	size_t	s2_length;
	char	*new_string;

	s1_length = 0;
	while (s1[s1_length] != '\0')
		s1_length++;
	s2_length = 0;
	while (s2[s2_length] != '\0')
		s2_length++;
	new_string = (char *)malloc(s1_length + s2_length + 1);
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (i < s1_length || i < s2_length)
	{
		if (i < s1_length)
			new_string[i] = s1[i];
		if (i < s2_length)
			new_string[s1_length + i] = s2[i];
		i++;
	}
	new_string[s1_length + s2_length] = '\0';
	return (new_string);
}
