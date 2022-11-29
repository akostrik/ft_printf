# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 13:57:13 by akostrik          #+#    #+#              #
#    Updated: 2022/11/29 17:36:56 by akostrik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Le Makefile compile ftlib à l’aide de son Makefile, puis compiler le projet

NAME    = libftprintf.a
SRCS    = ft_printf.c put_int_base_16_fd.c
OBJS    = ${SRCS:.c=.o}
HDRS    = .
CFLAGS  = -Wall -Wextra -Werror
LIBFT   = libft.a
CC      = cc

all: ${LIBFT}
	gcc -c ft_printf.c put_int_base_16_fd.c ${CFLAGS} -L./libft -lft
	ar rc ${NAME} ${OBJS} 

#all: ${NAME}

#${NAME}: ${LIBFT} ${OBJS}
#	ar rc ${NAME} ${OBJS} 

#%.o: %.c 
#	${CC} ${CFLAGS} -c -o $@ $< -L./libft -lft 
#	gcc -c ${CFLAGS} ft_printf.o put_int_base_16_fd.o -L./libft -lft

clean:
	rm -f ${OBJS}
	(cd libft && make clean)

fclean: clean
	rm -f ${NAME} 
	rm -f a.out
	(cd libft && make fclean)

re: fclean all

${LIBFT}:
	(cd libft && make)

.PHONY: all clean fclean re
