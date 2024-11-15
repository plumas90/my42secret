#include <stdio.h>
#include <assert.h>
#include "ft_iterative_power.c"

int	main(void)
{
	assert(ft_iterative_power(11, -1) == 0);
	assert(ft_iterative_power(11, 0) == 1);
	assert(ft_iterative_power(11, 1) == 11);
	assert(ft_iterative_power(11, 2) == 121);
	assert(ft_iterative_power(11, 3) == 1331);
	assert(ft_iterative_power(0, 0) == 1);
	printf("OK\n");
}

