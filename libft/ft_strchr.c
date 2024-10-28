/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:00:57 by minpark           #+#    #+#             */
/*   Updated: 2024/10/05 16:57:50 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h> 

char	*ft_strchr(const char *str, int i)
{
	int	num;

	num = 0;
	while (str[num])
	{
		if (str[num] == (char)i)
		{
			return ((char *)&str[num]);
		}
		num++;
	}
	if (i == '\0')
	{
		return ((char *)&str[num]);
	}
	return (NULL);
}
