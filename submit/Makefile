NAME    = libft.a
SRCS1   = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c 
SRCS2   = ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c
SRCS3   = ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c 
SRCS4   = ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c
SRCS5   = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c
SRCS6   = ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS    = ${SRCS1} ${SRCS2} ${SRCS3} ${SRCS4} ${SRCS5} ${SRCS6}
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
