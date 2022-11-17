/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:51:51 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/16 14:53:37 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// n: l’entier à convertir
// Retournr la chaîne de caractères représentant l’entier
// Retourne NULL si l’allocation échoue
// fonctions authorisées : malloc
// Alloue (avec malloc(3)) et retourne une chaîne de caractères représentant 
// l’entier ’n’ reçu en argument
// Les nombres négatifs doivent être gérés

#include <stdlib.h>
#include <limits.h>

static size_t	calculate_nb_bytes(int n)
{
	size_t	i;

	i = 0;
	if (n == INT_MIN)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i = 1;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	nb_bytes;
	size_t	i;

	nb_bytes = calculate_nb_bytes(n);
	str = (char *)malloc(nb_bytes);
	if (str == NULL)
		return (NULL);
	if (n == 0)
		return ("0");
	if (n == INT_MIN)
		return ("-2147483648");
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	i = nb_bytes - 1;
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}
