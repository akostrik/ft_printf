#include "ft_printf.h"

ssize_t	putchar_(char c, int fd)
{
	return (write(fd, &c, 1));
}

ssize_t	putstr(char *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}

unsigned long	pow_(unsigned long n, unsigned long k)
{
	unsigned int	i;
	unsigned long	res;

	i = 0;
	res = 1;
	while (i < k)
	{
		res *= n;
		i++;
	}
	return (res);
}
