#include <stdio.h>
#include <assert.h>
#include "ft_putnbr_base.c"

int	main(void)
{
	printf("assertion: base의 사이즈가 0이나 1이면 아무것도 출력하지 않는다\n");
	ft_putnbr_base(239283, "");
	ft_putnbr_base(239283, "0");
	ft_putnbr_base(239283, "a");
	printf("assertion: base에 같은 문자를 두번(이상) 반복하면 아무것도 출력하지 않는다\n");
	ft_putnbr_base(239283, "aa");
	ft_putnbr_base(239283, "99");
	printf("assertion: base에 + 또는 -를 포함하면 아무것도 출력하지 않는다\n");
	ft_putnbr_base(239283, "1+2");
	ft_putnbr_base(239283, "12-");
	ft_putnbr_base(239283, "+12-");
	printf("assertion: 주어진 nbr 값을 base 체계에 맞춰 출력한다\n");

	ft_putnbr_base(2133, "01");
	write(1, "\n", 1);
	printf("100001010101\n");

	ft_putnbr_base(2147483647, "01");
	write(1, "\n", 1);
	printf("1111111111111111111111111111111\n");

	ft_putnbr_base(2132893, "01234567");
	write(1, "\n", 1);
	printf("10105635\n");

	ft_putnbr_base(2132893, "0123456789abcdef");
	write(1, "\n", 1);
	printf("208b9d\n");

	printf("case: base 체계가 nbr보다 더 큰 경우\n");
	ft_putnbr_base(3, "0123456789abcdef");
	write(1, "\n", 1);
	printf("3\n");

	printf("case: 0\n");
	ft_putnbr_base(0, "0123456789abcdef");
	write(1, "\n", 1);
	printf("0\n");

	printf("assertion: 음수도 처리해야한다\n");
	ft_putnbr_base(-2147483648, "01");
	write(1, "\n", 1);
	printf("-10000000000000000000000000000000\n");

	ft_putnbr_base(-2147483648, "ab");
	write(1, "\n", 1);
	printf("-baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");

	ft_putnbr_base(-34334, "01234567");
	write(1, "\n", 1);
	printf("-103036\n");

	ft_putnbr_base(-34334, "abc");
	write(1, "\n", 1);
	printf("-bcaccaaccc\n");
}
