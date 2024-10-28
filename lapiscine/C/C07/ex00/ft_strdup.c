/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:45:20 by minpark           #+#    #+#             */
/*   Updated: 2024/07/10 19:13:56 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	length(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		++i;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*makesrc;
	int		leng;
	int		i;

	i = 0;
	leng = length(src);
	makesrc = (char *)malloc(leng + 1);
	if (makesrc == NULL)
	{
		return (NULL);
	}
	while (src[i])
	{
		makesrc[i] = src[i];
		++i;
	}
	makesrc[i] = '\0';
	return (makesrc);
}
