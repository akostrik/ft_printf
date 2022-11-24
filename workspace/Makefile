# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 13:57:13 by akostrik          #+#    #+#              #
#    Updated: 2022/11/17 14:46:47 by akostrik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Le Makefile compile ftlib à l’aide de son Makefile, puis compiler le projet

NAME    = libftprintf.a
SRCS    = ft_printf.c
OBJS    = ${SRCS:.c=.o}
HDRS    = .
CFLAGS  = -Wall -Wextra -Werror
LIBFT   = libft.a

${NAME}: clean ${LIBFT} ${OBJS}
	ar rc ${NAME} ${OBJS}
	#	gcc -c ${CFLAGS} ${OBJS} -o ${NAME}

.c.o:	gcc -c ${CFLAGS} -I ${HDRS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS}
	(cd ./libft && make clean)

fclean: clean
	rm -f ${NAME}
	(cd ./libft && make fclean)

re: fclean all

${LIBFT}:
	(cd ./libft && make)

.PHONY: all clean fclean re
