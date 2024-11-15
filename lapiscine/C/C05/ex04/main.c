#include <stdio.h>
#include <assert.h>
#include "ft_fibonacci.c"

int	main(void)
{
	assert(ft_fibonacci(-1) == -1);
	assert(ft_fibonacci(0) == 0);
	assert(ft_fibonacci(1) == 1);
	assert(ft_fibonacci(2) == 1);
	assert(ft_fibonacci(3) == 2);
	assert(ft_fibonacci(4) == 3);
	assert(ft_fibonacci(5) == 5);
	assert(ft_fibonacci(6) == 8);
	assert(ft_fibonacci(7) == 13);
	printf("OK :)\n");
}
