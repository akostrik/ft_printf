/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:57:16 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/29 11:55:50 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "workspace/ft_printf.h"

int main(void)
{
	char *str = "BCDEFG";
	char  c = 'A';
	int   n = 42;
	void *p = (void *)str;

	   printf("str %s, char %c, int %d, pointer %p\n",str,c,n,p);
	ft_printf("str %s, char %c, int %d, pointer %p\n",str,c,n,p);
}
