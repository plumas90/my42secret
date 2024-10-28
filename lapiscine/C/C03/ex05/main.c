#include <string.h>
#include <stdio.h>
#include "ft_strlcat.c"


int main(){

char dest[15] = "La Picine!";
	char src[6] = " Goal";
	printf("b_dest is %s \n", dest);
	printf("my  ft is %s / %d \n",dest, ft_strlcat(dest,src,17));
	}
