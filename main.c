/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:57:16 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/29 15:11:44 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "workspace/ft_printf.h"

int main(void)
{
	char *str = "ABCD";
	   printf("str %s\n",str);
	ft_printf("str %s\n\n",str);

	char c = 'A';
	   printf("char %c\n",c);
	ft_printf("char %c\n\n",c);

	void *p = (void *)(&c);
	   printf("pointer %p\n",p);
	ft_printf("pointer %p\n\n",p);


	// decimal number  16 bit %d INT_MIN ... INT_MAX
	// integer base 10 16 bit %i INT_MIN ... INT_MAX
	int n = -42;
	   printf("decimal     %%d = %d\n",n);
	   printf("int base 10 %%i = %i\n",n);
	ft_printf("decimal     %%d = %d\n",n);
	ft_printf("int base 10 %%i = %i\n\n",n);

	n = 0;
	   printf("decimal     %%d = %d\n",n);
	   printf("int base 10 %%i = %i\n",n);
	ft_printf("decimal     %%d = %d\n",n);
	ft_printf("int base 10 %%i = %i\n\n",n);

	n = INT_MAX;
	   printf("decimal     %%d = %d\n",n);
	   printf("int base 10 %%i = %i\n",n);
	ft_printf("decimal     %%d = %d\n",n);
	ft_printf("int base 10 %%i = %i\n\n",n);

	n = INT_MAX + 1;
	   printf("decimal     %%d = %d\t// INT_MAX + 1\n",n);
	   printf("int base 10 %%i =  %i\n",n);
	ft_printf("decimal     %%d = %d\n",n);
	ft_printf("int base 10 %%i =  %i\n\n",n);

	n = INT_MIN;
	   printf("decimal     %%d = %d\t// INT_MIN\n",n);
	   printf("int base 10 %%i =  %i\n",n);
	ft_printf("decimal     %%d = %d\n",n);
	ft_printf("int base 10 %%i =  %i\n\n",n);

	n = INT_MIN - 1;
	   printf("decimal     %%d = %d\t// INT_MIN - 1\n",n);
	   printf("int base 10 %%i = %i\n",n);
	ft_printf("decimal     %%d = %d\n",n);
	ft_printf("int base 10 %%i = %i\n\n",n);


// unsigned decimal number 16 bit %u 0 ... UINT_MAX
	unsigned int	un = 12;
	   printf("unsigned decimal %%u = %u\n",un);
	ft_printf("unsigned decimal %%u = %u\n\n",un);

	un = 0;
	   printf("unsigned decimal %%u = %u\n",un);
	ft_printf("unsigned decimal %%u = %u\n\n",un);

	un = INT_MAX;
	   printf("unsigned decimal %%u = %u\t// INT_MAX\n",un);
	ft_printf("unsigned decimal %%u = %u\n\n",un);

	un = -1;
	   printf("unsigned decimal %%u = %u\t// -1\n",un);
	ft_printf("unsigned decimal %%u = %u\n\n",un);

	un = UINT_MAX;
	   printf("unsigned decimal %%u = %u\t// UINT_MAX\n",un);
	ft_printf("unsigned decimal %%u = %u\n\n",un);

	un = UINT_MAX + 1;
	   printf("unsigned decimal %%u = %u\t\t\t// UINT_MAX + 1\n",un);
	ft_printf("unsigned decimal %%u = %u\n\n",un);

	un = UINT_MAX + 2;
	   printf("unsigned decimal %%u = %u\t\t\t// UINT_MAX + 2\n",un);
	ft_printf("unsigned decimal %%u = %u\n\n",un);

// unsigned int %u x 0 ... UINT_MAX
	unsigned int	x = 12;
	   printf("unsigned decimal %%x = %x\t\t\t// %d\n",x,x);
	ft_printf("unsigned decimal %%x = %x\n\n",x);

	x = -1;
	   printf("unsigned decimal %%x = %x\t\t// %d\n",x,x);
	ft_printf("unsigned decimal %%x = %x\n\n",x);

	x = -2;
	   printf("unsigned decimal %%x = %x\t\t// %d\n",x,x);
	ft_printf("unsigned decimal %%x = %x\n\n",x);

	x = 255;
	   printf("unsigned decimal %%x = %x\t\t// %d\n",x,x);
	ft_printf("unsigned decimal %%x = %x\n\n",x);

	x = 0;
	   printf("unsigned decimal %%x = %x\n",x);
	ft_printf("unsigned decimal %%x = %x\n\n",x);

	x = UINT_MAX;
	   printf("unsigned decimal %%x = %x\t\t// UINT_MAX\n",x);
	ft_printf("unsigned decimal %%x = %x\n\n",x);

	x = UINT_MAX + 1;
	   printf("unsigned decimal %%x = %x\t\t\t// UINT_MAX + 1\n",x);
	ft_printf("unsigned decimal %%x = %x\n\n",x);

	x = UINT_MAX;
	   printf("unsigned decimal %%X = %X\t\t// UINT_MAX\n",x);
	ft_printf("unsigned decimal %%X = %X\n\n",x);
}
