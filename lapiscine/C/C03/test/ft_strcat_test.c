/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:02:14 by minpark           #+#    #+#             */
/*   Updated: 2024/07/04 20:30:00 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
	{
		++i;
	}
	while (*src != '\0')
	{
		dest[i] = *src;
		src++;
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
int main()
{

		char dest[25] = "La Picine!";
	char src[6] = " Goal";
	printf("b_dest is %s \n", dest);
	ft_strcat(dest,src);
	printf("my  ft is %s \n", dest);
}
