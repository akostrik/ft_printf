# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 13:57:13 by akostrik          #+#    #+#              #
#    Updated: 2022/11/29 13:22:52 by akostrik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Le Makefile compile ftlib à l’aide de son Makefile, puis compiler le projet

NAME    = libftprintf.a
SRCS    = ft_printf.c itoa_base16.c
OBJS    = ${SRCS:.c=.o}
HDRS    = .
CFLAGS  = -Wall -Wextra -Werror
LIBFT   = libft.a
CC      = cc

${NAME}: ${LIBFT} ${OBJS}
	ar rc ${NAME} ${OBJS}

%.o: %.c ${INCLUDE}
	${CC} -c ${CFLAGS} -o $@ $<

all: ${NAME}

clean:
	rm -f ${OBJS} a.out
	(cd ../../01_libft/workspace && make clean)

fclean: clean
	rm -f ${NAME} a.out
	(cd ../../01_libft/workspace && make fclean)

re: fclean all

${LIBFT}:
	(cd ../../01_libft/workspace && make)
	
.PHONY: all clean fclean re
