/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:46:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/26 21:36:12 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Une bibliothèque qui contient ft_printf(), imitant printf() originale
// Contrairement à printf(), ne pas gérer de buffer
// %c caractère
// %s chaîne (telle que définie par la convention C)
// %p L’argument de pointeur void * doit être affiché en hexadécimal
// %d nombre décimal (base 10)
// %i entier en base 10
// %u nombre décimal non signé (base 10)
// %x nombre en hexadécimal (base 16) avec des lettres minuscules
// %X nombre en hexadécimal (base 16) avec des lettres majuscules
// %% %
// rendu : Makefile, *.h, */*.h, *.c, */*.c
// malloc free write libft
// обязательный аргумент – первое переданное число, если его не передавать, то
// не сможем найти адрес, по которому размещаются переменные в стеке

// a pointer to any object type may be converted to void*
// void* is useful in function parameters to allow passing values of any type
// void* can't be dereferenced (it would give a value of type void)
// void* : pointer arithmetic is not possible

static char	*pointer_to_str(void *p)
{
	size_t	i;
	char	*str;

	printf("\n\n&p      = %p\n",&p);
	printf("*(&p)   = %p = %c\n",*(&p),*(char*)(*(&p)));
	printf("*(&p+1) = %p = %c\n",*(&p+1),*(char*)(*(&p+1)));
	printf("*(&p+2) = %p = %c\n",*(&p+2),*(char*)(*(&p+2)));
	printf("*(&p+3) = %p = %c\n",*(&p+3),*(char*)(*(&p+3)));
	printf("p       = %p = %c\n",p,*(char*)p);
	printf("p+1     = %p = %c\n",p+1,*(char*)(p+1));
	printf("p+2     = %p = %c\n",p+2,*(char*)(p+2));
	printf("sizeof( p) = sizeof(%p) = %zu\n",p,sizeof(p));
	printf("sizeof(&p) = sizeof(%p) = %zu\n",&p,sizeof(&p));
	str = ft_calloc(14,1);
	if (str == NULL)
		return (NULL);
// 0x 56 12 21 0d a0 08
	str[0] = '0';
	str[1] = 'x';
	i = 2;
	while (i < 14)
	{
		// str[i] = *(char *)p;				BBBBBB
		// str = (char *)(p + 1);			CD
		//ft_memcpy(str+i, p+i-2, 1);	0xBCD
		ft_memcpy(str+i, ((char*)p+i-2), 1);
		i++;
	}
	printf("\npointer_to_str returns %s\n",str);
	return (str);
}

static void	ft_putpointer_fd(void *p, int fd)
{
	//if ( == NULL)
	ft_putstr_fd(pointer_to_str(p), fd);
}

int	ft_printf(const char *s, ...)
{
	va_list list_args;
	size_t	i;

	va_start(list_args, s);
	i = 0;
	while (i < ft_strlen((char *)s))
	{
		if (ft_strncmp(&s[i],"%s",2) == 0)
			ft_putstr_fd(va_arg(list_args, char*), 1);
		else if (ft_strncmp(&s[i],"%c",2) == 0)
			ft_putchar_fd(va_arg(list_args, int), 1);
		else if (ft_strncmp(&s[i],"%d",2) == 0)
			ft_putnbr_fd(va_arg(list_args, int), 1);
		else if (ft_strncmp(&s[i],"%p",2) == 0)
			ft_putpointer_fd(va_arg(list_args, void*), 1);
		else
		{
			ft_putchar_fd(s[i], 1);
			i--;
		}
		i += 2;
	}
	va_end(list_args);
	// free
	return (1);
}