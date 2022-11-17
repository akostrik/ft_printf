/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/10 13:52:04 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  l'ensemble des caractères ASCII, exceptés les caractères de contrôles 
// 0–8		control codes (NUL, etc.)
// 9		\t
// 10–13	whitespaces \n \v \f \r
// 14–31	control codes
// 127		backspace character (DEL)

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
