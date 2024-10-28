#include <stdio.h>
#include <assert.h>
#include "ft_atoi_base.c"

int	main(void)
{
	printf("assertion: base의 길이가 0이거나 1이면 0을 리턴한다\n");
	assert(ft_atoi_base("1111111", "1") == 0);
	assert(ft_atoi_base("", "0") == 0);
	printf("assertion: base 안에 같은 글자가 두개 들어가면 0을 리턴한다\n");
	assert(ft_atoi_base("1111111", "11") == 0);
	assert(ft_atoi_base("abcdeef", "aab") == 0);
	assert(ft_atoi_base("abcdeef", "aaa") == 0);
	printf("assertion: base 안에 +, -, whitespaces 포함시 0을 리턴한다\n");
	assert(ft_atoi_base("01010101", "01 ") == 0);
	assert(ft_atoi_base("01010101", "01\f") == 0);
	assert(ft_atoi_base("01010101", "\n01") == 0);
	assert(ft_atoi_base("01010101", "01\r") == 0);
	assert(ft_atoi_base("01010101", "\t01") == 0);
	assert(ft_atoi_base("01010101", "01\v") == 0);
	printf("assertion: 공백 다음에 부호가 오지 않으면 0을 반환한다.\n");
	assert(ft_atoi_base(" a0", "b0") == 0);
	assert(ft_atoi_base(" 10", "23") == 0);
	printf("assertion: 부호 다음에 숫자(base system)가 오지 않으면 0을 반환한다.\n");
	assert(ft_atoi_base(" + a0", "a0") == 0);
	assert(ft_atoi_base("\n+ a0", "a0") == 0);
	assert(ft_atoi_base("\t+-\na0", "a0") == 0);
	assert(ft_atoi_base("\f+-\ra0", "a0") == 0);
	assert(ft_atoi_base("\f\v+-\ra0", "a0") == 0);
	printf("case: base 체계 안의 글자가 오면 숫자의 합을 계산한다.\n");
	assert(ft_atoi_base("01010101", "01") == 85);
	assert(ft_atoi_base("abababab", "ab") == 85);
	assert(ft_atoi_base("+a0a0a0a", "a0") == 42);
	printf("assertion: 부호의 개수가 홀수개면 음사값이 나온다.\n");
	assert(ft_atoi_base(" \t\n+-1234", "0123456789") == -1234);
	assert(ft_atoi_base(" \r\n-abc", "abcdefgh") == -10);
	assert(ft_atoi_base("     \t\n   \v-------abc+a", "abcdefgh") == -10);
	assert(ft_atoi_base("     \t\n   \v-------abc-a", "abcdefgh") == -10);	
	assert(ft_atoi_base("     \t\n   \v-------abc\ta", "abcdefgh") == -10);
	assert(ft_atoi_base("     \t\n   \v-------abc\na", "abcdefgh") == -10);
	assert(ft_atoi_base("     \t\n   \v-------abc a", "abcdefgh") == -10);
	assert(ft_atoi_base("     \t\n   \v-------abcssa", "abcdefgh") == -10);

}
