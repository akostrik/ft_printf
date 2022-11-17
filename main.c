#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <bsd/string.h>
#include <errno.h>
#include "submit/libft.h"

int main(void)
{
	printf("\t\t\t\t\t\t\t\t\t\tlibc\tmy_func\n");
	char c = 'a';
	[[fallthrough]]
	printf("isalpha(%c\t%d\t%32b\t%8x)\t%d\t%d\n",c,c,c,c,isalpha(c),ft_isalpha(c)); 
}
