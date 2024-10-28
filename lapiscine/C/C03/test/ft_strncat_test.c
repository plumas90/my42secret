/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:31:18 by minpark           #+#    #+#             */
/*   Updated: 2024/07/04 20:34:02 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (dest[i] != '\0')
	{
		++i;
	}
	while (*src != '\0' && j < nb)
	{
		dest[i] = *src;
		src++;
		++i;
		++j;
	}
	dest[i] = '\0';
	return (dest);
}

int main()
{
		char dest[25] = "La Picine!";
	char src[6] = " Goal";
	printf("b_dest is %s \n", dest);
	ft_strncat(dest,src,3);
	printf("my  ft is %s \n", dest);
}
