/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:08:08 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/16 15:09:40 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s: La chaîne de laquelle extraire la nouvelle chaîne
// start: L’index de début de la nouvelle chaîne dans la chaîne s
// len: La taille maximale de la nouvelle chaîne
// Retourne la nouvelle chaîne de caractères, NULL si l’allocation échoue
// Fonctions autorisées : malloc
// Alloue (avec malloc(3)) et retourne une chaîne de caractères issue de’s’
// Cette nouvelle chaîne commence à l’index ’start’ 
// et a pour taille maximale ’len’

#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_length;
	char	*new_string;
	size_t	new_string_length;

	s_length = 0;
	while (s[s_length] != '\0')
		s_length++;
	if (start >= s_length)
		return (NULL);
	new_string_length = 0;
	while (s[start + new_string_length] != '\0' && new_string_length < len)
		new_string_length++;
	new_string = (char *)malloc(new_string_length + 1);
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (i < new_string_length)
	{
		new_string[i] = s[start + i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
