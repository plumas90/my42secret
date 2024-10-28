#include <string.h>
#include <stdio.h>
#include "ft_strstr.c"
int	main(void)
{
	char str[25] = "La che Picine! cheer";
	char to_find[6] = "cheer";
	printf("my  ft is %s \n", ft_strstr(str, to_find));
	printf("cp  ft is %s \n", strstr(str, to_find));
}
