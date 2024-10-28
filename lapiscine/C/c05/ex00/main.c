#include "ft_iterative_factorial.c"
#include <stdio.h>
#include <assert.h>

int	ft_iterative_factorial(int);

int	main(void)
{
	assert(ft_iterative_factorial(-1) == 0);
	assert(ft_iterative_factorial(0) == 1);
	assert(ft_iterative_factorial(1) == 1);
	assert(ft_iterative_factorial(2) == 2);
	assert(ft_iterative_factorial(3) == 6);
	assert(ft_iterative_factorial(4) == 24);
	assert(ft_iterative_factorial(5) == 120);
	printf("OK\n");
}
