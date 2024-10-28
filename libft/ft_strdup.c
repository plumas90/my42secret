/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:45:20 by minpark           #+#    #+#             */
/*   Updated: 2024/10/04 17:23:57 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*makesrc;
	int		leng;
	int		i;

	i = 0;
	leng = ft_strlen(src);
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
