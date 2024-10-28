#include <stdio.h>
#include <assert.h>
#include "ft_sqrt.c"

int	main(void)
{
	assert(ft_sqrt(0) == 0);
	assert(ft_sqrt(1) == 1);
	assert(ft_sqrt(2) == 0);
	assert(ft_sqrt(3) == 0);
	assert(ft_sqrt(4) == 2);
	assert(ft_sqrt(5) == 0);
	assert(ft_sqrt(9) == 3);
	assert(ft_sqrt(16) == 4);
	printf("OK :)\n");
}
