/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:24:00 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/29 22:37:05 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int			ft_printf(const char *str, ...);
ssize_t	putchar_(char c, int fd);
ssize_t putstr(char *s, int fd);
ssize_t put_pointer(void *p, int fd);
ssize_t	put_unsigned_int_base(unsigned int n, size_t base, int fd, char low_or_upper);
ssize_t	put_int_base_10(int n, int fd);

#endif
