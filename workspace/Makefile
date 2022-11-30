# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 13:57:13 by akostrik          #+#    #+#              #
#    Updated: 2022/11/30 23:23:44 by akostrik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Le Makefile compile ftlib à l’aide de son Makefile, puis compiler le projet

NAME    = libftprintf.a
SRCS    = ft_printf.c put_functions.c little_functons.c
OBJS    = ${SRCS:.c=.o}
HDRS    = .
CFLAGS  = -Wall -Wextra -Werror
LIBFT   = libft.a
CC      = cc

all: ${NAME}

${NAME}: ${LIBFT} ${OBJS}
	ar rc ${NAME} ${OBJS} 

%.o: %.c 
#	${CC} ${CFLAGS} -c -o $@ $< -L./libft -lft
	${CC} ${CFLAGS} -c -o $@ $< 

clean:
	rm -f ${OBJS}
	(cd libft && make clean)

fclean: clean
	rm -f ${NAME} 
	rm -f a.out
	(cd libft && make fclean)

re: fclean all

${LIBFT}:
	make -C libft 
	cp libft/$(LIBFT) $(NAME)
#	(cd libft && make) # 2 stroki pomenial

.PHONY: all clean fclean re
