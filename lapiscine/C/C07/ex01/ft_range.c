/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:07:44 by minpark           #+#    #+#             */
/*   Updated: 2024/07/10 21:10:46 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	gap;
	int	*arr;
	int	i;

	i = 0;
	if (min >= max)
	{
		return (0);
	}
	gap = max - min;
	arr = (int *)malloc(gap * 4);
	while (i < gap)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}
