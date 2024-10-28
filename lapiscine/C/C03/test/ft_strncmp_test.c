/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:50:47 by minpark           #+#    #+#             */
/*   Updated: 2024/07/04 19:56:09 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int a;
	
	a = 0;
        while(*s1 != '\0' && *s2 != '\0' && a < n)
        {
                if(*s1 > *s2)
                {
                        return (1);
                }
                else if (*s1 < *s2)
                {
                        return (-1);
                }
		++a;
		++s1;
		++s2;
        }
        return (0);
}

int main()
{
		char test1[10] = "La aPice!";
	char test2[15] = "La Picine! Goal";
	printf("my ft is %d \n", ft_strncmp(test1, test2,6));
	printf("cp ft is %d \n", strncmp(test1, test2, 6));
}
