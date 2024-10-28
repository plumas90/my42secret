/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:50:09 by minpark           #+#    #+#             */
/*   Updated: 2024/10/05 16:58:13 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int i)
{
	int	num;

	num = ft_strlen(str) - 1;
	if (i == '\0')
		return ((char *)&str[num + 1]);
	while (num >= 0)
	{
		if (str[num] == (char)i)
		{
			return ((char *)&str[num]);
		}
		num--;
	}
	return (NULL);
}
