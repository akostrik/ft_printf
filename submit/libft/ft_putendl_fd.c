/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:22:30 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/16 15:22:36 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s: La chaîne de caractères à écrire
// fd: Le descripteur de fichier sur lequel écrire
// fonctions autorisées : write
// Écrit La chaîne de caractères ’s’ sur le descripteur de 
// fichier donné suivie d’un retour à la ligne

#include <stdio.h>
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;
	char	c;

	i = 0;
	while (s[i] != '\0')
		i++;
	write(fd, s, i);
	c = '\n';
	write(fd, &c, 1);
}
