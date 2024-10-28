#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "ft_split.c"

int	main(void)
{
	char	*str;
	char	*charset;
	char	**dest;

	str = "eef";
	charset = "e";
	dest = ft_split(str, charset);
	assert(strcmp(dest[0], "f") == 0);
	assert(dest[1] == 0);

	printf("문제 쪼개기: split 하여 생성할 문자열 배열의 크기를 구한다\n");
	printf("ft_split_arr_len 함수 테스트: 구분자 두개로 갑싸진 문자열을 인정한다\n");
	printf("문자열 맨 처음이 구분자가 아닌경우, 맨 끝이 구분자인 경우\n");
	str = "avef,sfew.q21312,qwe221.qadxzcz,";
	charset = ",. ";
	dest = ft_split(str, charset);
	//assert(ft_split_arr_len(str, charset) == 5);
	assert(strcmp(dest[0], "avef") == 0);
	assert(strcmp(dest[1], "sfew") == 0);
	assert(strcmp(dest[2], "q21312") == 0);
	assert(strcmp(dest[3], "qwe221") == 0);
	assert(strcmp(dest[4], "qadxzcz") == 0);
	assert(dest[5] == 0);
	free(dest[0]);
	free(dest[1]);
	free(dest[2]);
	free(dest[3]);
	free(dest[4]);
	free(dest[5]);
	free(dest);

	str = "sfe.";
	charset = ",. ";
	dest = ft_split(str, charset);
	assert(strcmp(dest[0], "sfe") == 0);
	assert(dest[1] == 0);
	free(dest[0]);
	free(dest[1]);
	free(dest);

	str = "eef";
	charset = "f";
	dest = ft_split(str, charset);
	assert(strcmp(dest[0], "ee") == 0);
	assert(dest[1] == 0);
	free(dest[0]);
	free(dest[1]);
	free(dest);

	str = "eeeavef";
	charset = "af";
	dest = ft_split(str, charset);
	assert(strcmp(dest[0], "eee") == 0);
	assert(strcmp(dest[1], "ve") == 0);
	assert(dest[2] == 0);
	free(dest[0]);
	free(dest[1]);
	free(dest[2]);
	free(dest);

	printf("문자열이 맨 처음이 구분자, 맨 끝이 구분자인 경우\n");
	str = "...avef,sfew.q21312,qwe221.qadxzcz,";
	charset = ",. ";
	dest = ft_split(str, charset);
	assert(strcmp(dest[0], "avef") == 0);
	assert(strcmp(dest[1], "sfew") == 0);
	assert(strcmp(dest[2], "q21312") == 0);
	assert(strcmp(dest[3], "qwe221") == 0);
	assert(strcmp(dest[4], "qadxzcz") == 0);
	assert(dest[5] == 0);
	free(dest[0]);
	free(dest[1]);
	free(dest[2]);
	free(dest[3]);
	free(dest[4]);
	free(dest[5]);
	free(dest);

	str = ".sfe,";
	charset = ",. ";
	dest = ft_split(str, charset);
	assert(strcmp(dest[0], "sfe") == 0);
	assert(dest[1] == 0);
	free(dest[0]);
	free(dest[1]);
	free(dest);

	str = "avef";
	charset = "af";
	dest = ft_split(str, charset);
	assert(strcmp(dest[0], "ve") == 0);
	assert(dest[1] == 0);
	free(dest[0]);
	free(dest[1]);
	free(dest);

	printf("문자열이 맨 처음이 구분자, 맨 끝은 구분자가 아닌 경우\n");
	str = "avef";
	charset = "a";
	dest = ft_split(str, charset);
	assert(strcmp(dest[0], "vef") == 0);
	assert(dest[1] == 0);
	free(dest[0]);
	free(dest[1]);
	free(dest);

	printf("문자열 맨 처음이 구분자가 아닌 경우, 맨 끝도 구분자가 아닌 경우\n");
	str = "sfe";
	charset = ",. ";
	dest = ft_split(str, charset);
	assert(strcmp(dest[0], "sfe") == 0);
	assert(dest[1] == 0);
	free(dest[0]);
	free(dest[1]);
	free(dest);

	str = "avef";
	charset = ",. ";
	dest = ft_split(str, charset);
	assert(strcmp(dest[0], "avef") == 0);
	assert(dest[1] == 0);
	free(dest[0]);
	free(dest[1]);
	free(dest);

//	str = "wekejrekj";
//	charset = "ek";
//	dest = ft_split(str, charset);
//	assert(strcmp(dest[0], "w") == 0);
//	assert(strcmp(dest[1], "jr") == 0);
//	assert(strcmp(dest[2], "j") == 0);
//	assert(dest[3] == 0);
//	free(dest[0]);
//	free(dest[1]);
//	free(dest[2]);
//	free(dest[3]);
//	free(dest);

	printf("문자열 모두가 구분자에 포함되는 경우: 길이가 0이다\n");
	printf("배열 안에는 빈문자열을 포함하지 않는다\n");
	str = "....";
	charset = ",. ";
	dest = ft_split(str, charset);
	assert(dest[0] == 0);
	free(dest[0]);
	free(dest);

	printf("문자열 모두가 구분자에 하나도 포함되지 않는 경우: 길이가 1 그대로 출력\n");
	str = "...avef,sfew.q21312,qwe221.qadxzcz,";
	charset = "0";
	dest = ft_split(str, charset);
	assert(strcmp(dest[0], "...avef,sfew.q21312,qwe221.qadxzcz,") == 0);
	assert(dest[1] == 0);
	free(dest[0]);
	free(dest[1]);
	free(dest);

	printf("문자열이 빈 문자열인 경우:길이가 0이다\n");
	str = "";
	charset = ",. ";
	dest = ft_split(str, charset);
	assert(dest[0] == 0);
	free(dest[0]);
	free(dest);

	printf("구분자가 빈 문자열인 경우: 문자열 그대로 출력\n");
	str = "...avef,sfew.q21312,qwe221.qadxzcz,";
	charset = "";
	dest = ft_split(str, charset);
	assert(strcmp(dest[0], "...avef,sfew.q21312,qwe221.qadxzcz,") == 0);
	assert(dest[1] == 0);
	free(dest[0]);
	free(dest[1]);
	free(dest);

	str = "svwefklwejfwe";
	charset = "";
	dest = ft_split(str, charset);
	assert(strcmp(dest[0], "svwefklwejfwe") == 0);
	assert(dest[1] == 0);
	free(dest[0]);
	free(dest[1]);
	free(dest);
}
