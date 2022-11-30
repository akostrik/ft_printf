/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:57:16 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/30 13:06:17 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "workspace/ft_printf.h"

int main(void)
{
	size_t a;
	char *str = "ABCD";

	a =    printf("str\t\t %s",str);
	printf("\t\t\t\treturns %zu\n",a);
	a = ft_printf("str\t\t %s",str);
	printf("\t\t\t\treturns %zu\n\n",a);

	str = "";
	a =    printf("str\t\t [%s]",str);
	printf("\t\t\t\treturns %zu\n",a);
	a = ft_printf("str\t\t [%s]",str);
	printf("\t\t\t\treturns %zu\n\n",a);

	char c = 'A';
	a =   printf("char\t\t %c",c);
	printf("\t\t\t\treturns %zu\n",a);
	a = ft_printf("char\t\t %c",c);
	printf("\t\t\t\treturns %zu\n\n",a);

	c = 0;
	a =   printf("char\t\t [%c]",c);
	printf("\t\t\t\treturns %zu\n",a);
	a = ft_printf("char\t\t [%c]",c);
	printf("\t\t\t\treturns %zu\n\n",a);

	c = '0';
	a =   printf("char\t\t [ %c ]",c);
	printf("\t\t\t\treturns %zu\n",a);
	a = ft_printf("char\t\t [ %c ]",c);
	printf("\t\t\t\treturns %zu\n\n",a);

	c = '0' - 256;
	a =   printf("char\t\t [ %c ]",c);
	printf("\t\t\t\treturns %zu\n",a);
	a = ft_printf("char\t\t [ %c ]",c);
	printf("\t\t\t\treturns %zu\n\n",a);

	c = '0' + 256;
	a =   printf("char\t\t [ %c ]",c);
	printf("\t\t\t\treturns %zu\n",a);
	a = ft_printf("char\t\t [ %c ]",c);
	printf("\t\t\t\treturns %zu\n\n",a);

	char c1 ='0', c2 = 0, c3 = '1';
	a =   printf("char\t\t %c %c %c ",c);
	printf("\t\t\t\treturns %zu\n",a);
	a = ft_printf("char\t\t %c %c %c ",c);
	printf("\t\t\t\treturns %zu\n\n",a);

	c1 =' '; c2 = ' '; c3 = ' ';
	a =   printf("char\t\t %c %c %c ",c);
	printf("\t\t\t\treturns %zu\n",a);
	a = ft_printf("char\t\t %c %c %c ",c);
	printf("\t\t\t\treturns %zu\n\n",a);

	c1 ='1'; c2 = '2'; c3 = '3';
	a =   printf("char\t\t %c %c %c ",c);
	printf("\t\t\t\treturns %zu\n",a);
	a = ft_printf("char\t\t %c %c %c ",c);
	printf("\t\t\t\treturns %zu\n\n",a);

	c1 ='2'; c2 = '1'; c3 = 0;
	a =   printf("char\t\t %c %c %c ",c);
	printf("\t\t\t\treturns %zu\n",a);
	a = ft_printf("char\t\t %c %c %c ",c);
	printf("\t\t\t\treturns %zu\n\n",a);

	c1 = 0; c2 = '1'; c3 = '2';
	a =   printf("char\t\t %c %c %c ",c);
	printf("\t\t\t\treturns %zu\n",a);
	a = ft_printf("char\t\t %c %c %c ",c);
	printf("\t\t\t\treturns %zu\n\n",a);

	/////////////////////////////////////////////
	void *p = (void *)(&c);
	a =   printf("pointer\t\t %p",p);
	printf("\t\t\treturns %zu\n",a);
	a = ft_printf("pointer\t\t %p",p);
	printf("\t\t\treturns %zu\n\n",a);

	p = NULL;
	a =   printf("pointer\t\t %p",p);
	printf("\t\t\t\treturns %zu\n",a);
	a = ft_printf("pointer\t\t %p",p);
	printf("\t\t\t\treturns %zu\n\n",a);

	p = -1;
	a =   printf("pointer\t\t %p",p);
	printf("\t\treturns %zu\n",a);
	a = ft_printf("pointer\t\t %p",p);
	printf("\t\treturns %zu\n\n",a);

	p = 1;
	a =   printf("pointer\t\t %p",p);
	printf("\t\t\t\treturns %zu\n",a);
	a = ft_printf("pointer\t\t %p",p);
	printf("\t\t\t\treturns %zu\n\n",a);

	p = 15;
	a =   printf("pointer\t\t %p",p);
	printf("\t\t\t\treturns %zu\n",a);
	a = ft_printf("pointer\t\t %p",p);
	printf("\t\t\t\treturns %zu\n\n",a);

	p = 16;
	a =   printf("pointer\t\t %p",p);
	printf("\t\t\t\treturns %zu\n",a);
	a = ft_printf("pointer\t\t %p",p);
	printf("\t\t\t\treturns %zu\n\n",a);

	p = 17;
	a =   printf("pointer\t\t %p",p);
	printf("\t\t\t\treturns %zu\n",a);
	a = ft_printf("pointer\t\t %p",p);
	printf("\t\t\t\treturns %zu\n\n",a);

	p = LONG_MIN;
	a =   printf("pointer\t\t %p",p);
	printf("\t\treturns %zu\n",a);
	a = ft_printf("pointer\t\t %p",p);
	printf("\t\treturns %zu\n\n",a);

	p = LONG_MAX;
	a =   printf("pointer\t\t %p",p);
	printf("\t\treturns %zu\n",a);
	a = ft_printf("pointer\t\t %p",p);
	printf("\t\treturns %zu\n\n",a);

	p = INT_MIN;
	a =   printf("pointer\t\t %p",p);
	printf("\t\treturns %zu\n",a);
	a = ft_printf("pointer\t\t %p",p);
	printf("\t\treturns %zu\n\n",a);

	p = INT_MAX;
	a =   printf("pointer\t\t %p",p);
	printf("\t\t\treturns %zu\n",a);
	a = ft_printf("pointer\t\t %p",p);
	printf("\t\t\treturns %zu\n\n",a);

	p = ULONG_MAX;
	a =   printf("pointer\t\t %p",p);
	printf("\t\treturns %zu\n",a);
	a = ft_printf("pointer\t\t %p",p);
	printf("\t\treturns %zu\n\n",a);

	p = -ULONG_MAX;
	a =   printf("pointer\t\t %p",p);
	printf("\t\t\t\treturns %zu\n",a);
	a = ft_printf("pointer\t\t %p",p);
	printf("\t\t\t\treturns %zu\n\n",a);

	void *p1 = 0;
	void *p2 = 0;
	a =   printf("pointer\t\t %p %p",p1,p2);
	printf("\t\t\treturns %zu\n",a);
	a = ft_printf("pointer\t\t %p %p",p1,p2);
	printf("\t\t\treturns %zu\n\n",a);

	// decimal number  16 bit %d INT_MIN ... INT_MAX
	// integer base 10 16 bit %i INT_MIN ... INT_MAX
	int n = 42;
	a =   printf("decimal\t\t %%d = %d",n);
	printf("\t\t\treturns %zu\n",a);
	a = ft_printf("decimal\t\t %%d = %d",n);
	printf("\t\t\treturns %zu\n\n",a);

	a =   printf("int\t\t %%i = %i",n);
	printf("\t\t\treturns %zu\n",a);
	a = ft_printf("int\t\t %%i = %i",n);
	printf("\t\t\treturns %zu\n\n",a);

	n = -42;
	a =   printf("decimal\t\t %%d = %d",n);
	printf("\t\t\treturns %zu\n",a);
	a = ft_printf("decimal\t\t %%d = %d",n);
	printf("\t\t\treturns %zu\n\n",a);

	a =   printf("int\t\t %%i = %i",n);
	printf("\t\t\treturns %zu\n",a);
	a = ft_printf("int\t\t %%i = %i",n);
	printf("\t\t\treturns %zu\n\n",a);

	n = 0;
	a =   printf("decimal\t\t %%d = %d",n);
	printf("\t\t\t\treturns %zu\n",a);
	a = ft_printf("decimal\t\t %%d = %d",n);
	printf("\t\t\t\treturns %zu\n\n",a);

	a =   printf("int\t\t %%i = %i",n);
	printf("\t\t\t\treturns %zu\n",a);
	a = ft_printf("int\t\t %%i = %i",n);
	printf("\t\t\t\treturns %zu\n\n",a);
	
	n = INT_MAX;
	a =   printf("decimal\t\t %%d = %d",n);
	printf("\t\treturns %zu\n",a);
	a = ft_printf("decimal\t\t %%d = %d",n);
	printf("\t\treturns %zu\n\n",a);

	a =   printf("int\t\t %%i = %i",n);
	printf("\t\treturns %zu\n",a);
	a = ft_printf("int\t\t %%i = %i",n);
	printf("\t\treturns %zu\n\n",a);

	n = INT_MAX + 1;
	a =   printf("decimal\t\t %%d = %d",n);
	printf("\t\treturns %zu\t// INT_MAX + 1\n",a);
	a = ft_printf("decimal\t\t %%d = %d",n);
	printf("\t\treturns %zu\n\n",a);

	n = INT_MAX + 1;
	a =   printf("int\t\t %%i = %i",n);
	printf("\t\treturns %zu\n",a);
	a = ft_printf("int\t\t %%i = %i",n);
	printf("\t\treturns %zu\n\n",a);

	n = INT_MIN;
	a =   printf("decimal\t\t %%d = %d",n);
	printf("\t\treturns %zu\t// INT_MIN\n",a);
	a = ft_printf("decimal\t\t %%d = %d",n);
	printf("\t\treturns %zu\n\n",a);

	n = INT_MIN;
	a =   printf("int\t\t %%i = %i",n);
	printf("\t\treturns %zu\n",a);
	a = ft_printf("int\t\t %%i = %i",n);
	printf("\t\treturns %zu\n\n",a);

	n = INT_MIN - 1;
	a =   printf("decimal\t\t %%d = %d",n);
	printf("\t\treturns %zu\t// INT_MIN - 1\n",a);
	a = ft_printf("decimal\t\t %%d = %d",n);
	printf("\t\treturns %zu\n\n",a);
	
	n = LONG_MAX;
	a =   printf("int\t\t %%i = %i",n);
	printf("\t\t\treturns %zu\t// LONG_MAX\n",a);
	a = ft_printf("int\t\t %%i = %i",n);
	printf("\t\t\treturns %zu\n\n",a);

	n = LONG_MIN;
	a =   printf("int\t\t %%i = %i",n);
	printf("\t\t\t\treturns %zu\t// LONG_MIN\n",a);
	a = ft_printf("int\t\t %%i = %i",n);
	printf("\t\t\t\treturns %zu\n\n",a);

	n = UINT_MAX;
	a =   printf("int\t\t %%i = %i",n);
	printf("\t\t\treturns %zu\t// UINT_MAX\n",a);
	a = ft_printf("int\t\t %%i = %i",n);
	printf("\t\t\treturns %zu\n\n",a);

	n = ULONG_MAX;
	a =   printf("int\t\t %%i = %i",n);
	printf("\t\t\treturns %zu\t// ULONG_MAX\n",a);
	a = ft_printf("int\t\t %%i = %i",n);
	printf("\t\t\treturns %zu\n\n",a);

	n = 9223372036854775807LL;
	a =   printf("int\t\t %%i = %i",n);
	printf("\t\t\treturns %zu\t// 9223372036854775807LL\n",a);
	a = ft_printf("int\t\t %%i = %i",n);
	printf("\t\t\treturns %zu\n\n",a);


// unsigned decimal number 16 bit %u 0 ... UINT_MAX
	unsigned int	un = 12;
	a =    printf("unsigned decimal %%u = %u",un);
	printf("\t\t\treturns %zu\t // 12\n",a);
	a = ft_printf("unsigned decimal %%u = %u",un);
	printf("\t\t\treturns %zu\n\n",a);

	un = 12;
	a =    printf("int              %%i = %i",n);
	printf("\t\t\treturns %zu\t // 12\n",a);
	a = ft_printf("int              %%i = %i",n);
	printf("\t\t\treturns %zu\n\n",a);

	un = 0;
	a =   printf("unsigned decimal %%u = %u",un);
	printf("\t\t\t\treturns %zu\t // 0\n",a);
	a = ft_printf("unsigned decimal %%u = %u",un);
	printf("\t\t\t\treturns %zu\n\n",a);

	un = 0;
	a =   printf("int              %%i = %i",n);
	printf("\t\t\treturns %zu\t // 0\n",a);
	a = ft_printf("int              %%i = %i",n);
	printf("\t\t\treturns %zu\n\n",a);

	un = INT_MAX;
	a =   printf("unsigned decimal %%u = %u",un);
	printf("\t\treturns %zu\t// INT_MAX\n",a);
	a =  ft_printf("unsigned decimal %%u = %u",un);
	printf("\t\treturns %zu\n\n",a);

	un = INT_MAX;
	a =   printf("int              %%i = %i",n);
	printf("\t\t\treturns %zu\t// INT_MAX\n",a);
	a = ft_printf("int              %%i = %i",n);
	printf("\t\t\treturns %zu\n\n",a);

	un = -1;
	a =   printf("unsigned decimal %%u = %u",un);
	printf("\t\treturns %zu\t// -1\n",a);
	a = ft_printf("unsigned decimal %%u = %u",un);
	printf("\t\treturns %zu\n\n",a);

	un = -1;
	a =   printf("int              %%i = %i",n);
	printf("\t\t\treturns %zu\t// -1\n",a);
	a = ft_printf("int              %%i = %i",n);
	printf("\t\t\treturns %zu\n\n",a);

	un = UINT_MAX;
	a =   printf("unsigned decimal %%u = %u",un);
	printf("\t\treturns %zu\t// UINT_MAX\n",a);
	a = ft_printf("unsigned decimal %%u = %u",un);
	printf("\t\treturns %zu\n\n",a);

	un = UINT_MAX;
	a =   printf("int              %%i = %i",n);
	printf("\t\t\treturns %zu\t// UINT_MAX\n",a);
	a = ft_printf("int              %%i = %i",n);
	printf("\t\t\treturns %zu\n\n",a);

	un = UINT_MAX + 1;
	a =    printf("unsigned decimal %%u = %u",un);
	printf("\t\t\t\treturns %zu\t// UINT_MAX + 1\n",a);
	a = ft_printf("unsigned decimal %%u = %u",un);
	printf("\t\t\t\treturns %zu\n\n",a);

	un = UINT_MAX + 1;
	a =    printf("int              %%i = %i",n);
	printf("\t\t\treturns %zu\t// UINT_MAX + 1\n",a);
	a = ft_printf("int              %%i = %i",n);
	printf("\t\t\treturns %zu\n\n",a);

	un = UINT_MAX + 2;
	a =    printf("unsigned decimal %%u = %u",un);
	printf("\t\t\t\treturns %zu\t// UINT_MAX + 2\n",a);
	a = ft_printf("unsigned decimal %%u = %u",un);
	printf("\t\t\t\treturns %zu\n\n",a);

	un = UINT_MAX + 2;
	a =    printf("int              %%i = %i",n);
	printf("\t\t\treturns %zu\t// UINT_MAX + 2\n",a);
	a = ft_printf("int              %%i = %i",n);
	printf("\t\t\treturns %zu\n\n",a);

// unsigned int %u x 0 ... UINT_MAX
	unsigned int	x = 12;
	a =   printf("unsigned decimal %%x = %x",x);
	printf("\t\t\t\treturns %zu\t// %d\n",a,x);
	a = ft_printf("unsigned decimal %%x = %x",x);
	printf("\t\t\t\treturns %zu\n\n",a);

	x = -12;
	a =   printf("unsigned decimal %%x = %x",x);
	printf("\t\t\treturns %zu\t// %d\n",a,x);
	a = ft_printf("unsigned decimal %%x = %x",x);
	printf("\t\t\treturns %zu\n\n",a);

	x = -1;
	a =   printf("unsigned decimal %%x = %x",x);
	printf("\t\t\treturns %zu\t// %d\n",a,x);
	a = ft_printf("unsigned decimal %%x = %x",x);
	printf("\t\t\treturns %zu\n\n",a);

	x = -2;
	a =   printf("unsigned decimal %%x = %x",x);
	printf("\t\t\treturns %zu\t// %d\n",a,x);
	a = ft_printf("unsigned decimal %%x = %x",x);
	printf("\t\t\treturns %zu\n\n",a);

	x = 255;
	a =    printf("unsigned decimal %%x = %x",x);
	printf("\t\t\treturns %zu\t// %d\n",a,x);
	a = ft_printf("unsigned decimal %%x = %x",x);
	printf("\t\t\treturns %zu\n\n",a);

	x = 0;
	a =   printf("unsigned decimal %%x = %x",x);
	printf("\t\t\t\treturns %zu\t// %d\n",a,x);
	a = ft_printf("unsigned decimal %%x = %x",x);
	printf("\t\t\t\treturns %zu\n\n",a);

	x = UINT_MAX;
	a =   printf("unsigned decimal %%x = %x",x);
	printf("\t\t\treturns %zu\t// UINT_MAX\n",a);
	a = ft_printf("unsigned decimal %%x = %x",x);
	printf("\t\t\treturns %zu\n\n",a);

	x = UINT_MAX + 1;
	a =    printf("unsigned decimal %%x = %x",x);
	printf("\t\t\t\treturns %zu\t// UINT_MAX + 1\n",a);
	a = ft_printf("unsigned decimal %%x = %x",x);
	printf("\t\t\t\treturns %zu\n\n",a);

	x = UINT_MAX;
	a =    printf("unsigned decimal %%X = %X",x);
	printf("\t\t\treturns %zu\t// UINT_MAX\n",a);
	a = ft_printf("unsigned decimal %%X = %X",x);
	printf("\t\t\treturns %zu\n\n",a);
}
