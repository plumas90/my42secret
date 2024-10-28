/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:58:08 by minpark           #+#    #+#             */
/*   Updated: 2024/07/04 20:00:57 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
	while(*s1 != '\0' && *s2 != '\0')
	{
		if(*s1 > *s2)
		{
			return (1);
		}
		else if (*s1 < *s2)
		{
			return (-1);
		}
		++s1;
		++s2;
	}
	return (0);
}
int main()
{
		char test1[10] = "aa Picine!";
	char test2[15] = "bb Picine! Goal";
	printf("my ft is %d \n", ft_strcmp(test1, test2));
	printf("cp ft is %d \n", strcmp(test1, test2));
}
