#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <bsd/string.h>
#include <errno.h>
#include "submit/ft_printf.h"

// Fichiers de rendu : Makefile, *.h, */*.h, *.c, */*.c
// Fonctions externes autorisées : malloc free write va_start va_arg va_copy va_end
// Libft autorisée
// Une bibliothèque qui contient ft_printf(), imitant printf() originale
// Contrairement à printf() originale, vous ne devez pas gérer de buffer
// ar pour créer votre bibliothèque, libtool est interdite
// Gérer les conversions suivantes : cspdiuxX%
// %c Affiche un seul caractère
// %s Affiche une chaîne de caractères (telle que définie par la convention C)
// %p L’argument de pointeur void * doit être affiché en hexadécimal
// %d Affiche un nombre décimal (base 10)
// %i Affiche un entier en base 10
// %u Affiche un nombre décimal non signé (base 10)
// %x Affiche un nombre en hexadécimal (base 16) avec des lettres minuscules
// %X Affiche un nombre en hexadécimal (base 16) avec des lettres majuscules
// %% Affiche %

int main(void)
{
	printf("\"%%c\" 'A' ->\t\t\t\t\t"); 
	printf("%c\n",'A'); 
	ft_printf("%c"); 
}
