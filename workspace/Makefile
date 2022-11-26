# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 13:57:13 by akostrik          #+#    #+#              #
#    Updated: 2022/11/26 20:45:17 by akostrik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Le Makefile compile ftlib à l’aide de son Makefile, puis compiler le projet

NAME    = libftprintf.a
SRCS    = ft_printf.c
OBJS    = ${SRCS:.c=.o}
HDRS    = .
CFLAGS  = -Wall -Wextra -Werror
LIBFT   = libft.a

${NAME}: ${LIBFT} ${OBJS}
	ar rc ${NAME} ${OBJS}
#	gcc -c ${CFLAGS} -I ${HDRS} ${OBJS} -o ${NAME}

#.c.o: gcc -c ${CFLAGS} -I ${HDRS} ${OBJS} -o ${NAME}

%.o: %.c ${INCLUDE}
	gcc -c ${CFLAGS} -o $@ $<

all: ${NAME}

clean:
	rm -f ${OBJS} a.out
	(cd ../../01_libft/workspace && make clean)

fclean: clean
	rm -f ${NAME} a.out
	(cd ../../01_libft/workspace && make fclean)

re: fclean all

${LIBFT}:
#	(cd ./libft && make)
	(cd ../../01_libft/workspace && make)
	
.PHONY: all clean fclean re
