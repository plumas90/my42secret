#include <stdio.h>
#include <assert.h>
#include "ft_find_next_prime.c"

int	main(void)
{
	assert(ft_find_next_prime(-1) == 2);
	assert(ft_find_next_prime(1) == 2);
	assert(ft_find_next_prime(2) == 2);
	assert(ft_find_next_prime(6) == 7);
	assert(ft_find_next_prime(12) == 13);
	assert(ft_find_next_prime(17) == 17);
	printf("OK :)\n");
}
