/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:33:17 by minpark           #+#    #+#             */
/*   Updated: 2024/07/05 14:20:25 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
unsigned int	length_check(char *ch)
{
	unsigned int	i;

	i = 0;
	while (*ch)
	{
		i++;
		ch++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_length;
	unsigned int	dest_length;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	dest_length = length_check(dest);
	src_length = length_check(src);
	i = dest_length;
	if (size > dest_length)
	{
		while (j < (size - 1 - dest_length))
		{
			dest[i] = src[j];
			++i;
			++j;
		}
		dest[i] = '\0';
	}
	if (dest_length < size)
		return (src_length + size);
	else
		return (src_length + dest_length);
}
int main()
{
		char dest[21] = "La Picine!";
	char src[6] = " Goal";
	printf("b_dest is %s \n", dest);
	printf("my  ft is %s / %d \n",dest, ft_strlcat(dest,src,21));
}
