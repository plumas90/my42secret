#include <assert.h>
#include <stdio.h>
#include "ft_recursive_factorial.c"
int	main(void)
{
	assert(ft_recursive_factorial(-1) == 0);
	assert(ft_recursive_factorial(0) == 1);
	assert(ft_recursive_factorial(1) == 1);
	assert(ft_recursive_factorial(3) == 6);
	assert(ft_recursive_factorial(5) == 120);
	printf("OK\n");
}
