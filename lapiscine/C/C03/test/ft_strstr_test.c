/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:31:55 by minpark           #+#    #+#             */
/*   Updated: 2024/07/04 22:44:26 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

char *ft_strstr(char *str, char *to_find)
{
	size_t	i;

	if (to_find[0] == '\0')
	{
		return (str);
	}
	while (*str != '\0')
	{
		i = 0;
		while (*(str + i) == *(to_find + i))
		{
			i++;
			if (*(to_find + i) == '\0')
				return (str);
		}
		str++;
	}
	return ("\0");
}

int main()
{
		char str[25] = "La che Picine! cheer";
	char to_find[6] = "cheer";
	printf("my  ft is %s \n", ft_strstr(str, to_find));
	printf("cp  ft is %s \n", strstr(str, to_find));
}
