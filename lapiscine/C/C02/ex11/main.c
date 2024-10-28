#include <assert.h>
#include <stdio.h>
#include "ft_putstr_non_printable.c"
int main(void)
{
    char    str1[99] = "Coucou\ntu vas bien ?";
	char	str2[99] = "moi aussi je vais très bien";
	ft_putstr_non_printable(str1);
	printf("%s\n", "Coucou\0atu vas bien ?");
	//ft_putstr_non_printable(str2);
//	printf("%s\n");
}
