/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:03:43 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/17 15:57:09 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#ifndef CONVERSION_H
# define CONVERSION_H

typedef struct s_conversion
{
	size_t	pos_in_str;
	char	c;
	size_t	nb_bytes;
}	t_conversion;
#endif