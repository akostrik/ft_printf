NAME    = libft.a
SRCS    = ft_isalpha.c
OBJS    = ${SRCS:.c=.o}
HDRS    = .
CFLAGS  = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: clean ${OBJS} 
	gcc -c ${OBJS} -o ${NAME}
	ar rc libft.a ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
