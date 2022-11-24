/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:46:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/17 17:05:07 by akostrik         ###   ########.fr       */
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
// malloc free write
// Libft autorisée
/// void va_start(va_list ap, paramN) макрос инициализирует args для извлечения
// доп аргументов, которые идут после paramN. Параметр не должен быть register,
// не может иметь типа массива или указателя на функцию
/// void va_end(va_list ap) для нормального завершения работы, в паре с va_start
/// va_arg макрос, получает указатель на первый аргумент и двигается
/// void va_copy(va_list dest, va_list src) копирует src в dest, начиная с C++11
// обязательный аргумент – первое переданное число, если его не передавать, то
// не сможем найти адрес, по которому размещаются переменные в стеке

static int	is_conversion(const char *str)
{
	if (str[0] == '%')
	{
		if (str[1] == 'c')
			return (1);
		if (str[1] == 's')
			return (1);
		if (str[1] == 'p')
			return (1);
		if (str[1] == 'd')
			return (1);
		if (str[1] == 'i')
			return (1);
		if (str[1] == 'u')
			return (1);
		if (str[1] == 'x')
			return (1);
		if (str[1] == 'X')
			return (1);
		if (str[1] == '%')
			return (1);
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list args;
	size_t	i;

	printf("I have got %s : \n",s);
	va_start(args, s); // указатель на первый элемент
	i = 0;
	while (i < ft_strlen((char *)s))
	{
		printf("%c\n",s[i]);
		printf("%zu < %zu - 1 ?\n",i,ft_strlen((char *)s));
		if (is_conversion(&s[i]) == 1)
			printf("conversion %s\n",va_arg(args, char*));
		i++;
	}
	va_end(args);
	return (1);
}
