NAME    = libftprintf.a
SRCS    = ft_printf.c
OBJS    = ${SRCS:.c=.o}
HDRS    = .
CFLAGS  = -Wall -Wextra -Werror

${NAME}: clean ${OBJS} 
	gcc -c ${OBJS} -o ${NAME}
	ar rc ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
