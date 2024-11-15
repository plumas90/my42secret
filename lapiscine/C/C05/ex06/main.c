#include <assert.h>
#include <stdio.h>
#include "ft_is_prime.c"

int	main(void)
{
	assert(ft_is_prime(-1) == 0);
	assert(ft_is_prime(0) == 0);
	assert(ft_is_prime(1) == 0);
	assert(ft_is_prime(2) == 1);
	assert(ft_is_prime(3) == 1);
	assert(ft_is_prime(4) == 0);
	assert(ft_is_prime(5) == 1);
	assert(ft_is_prime(6) == 0);
	assert(ft_is_prime(7) == 1);
	assert(ft_is_prime(11) == 1);
	assert(ft_is_prime(12) == 0);
	assert(ft_is_prime(13) == 1);
	printf("OK :)\n");
}
