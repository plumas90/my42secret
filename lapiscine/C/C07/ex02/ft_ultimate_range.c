/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:56:38 by minpark           #+#    #+#             */
/*   Updated: 2024/07/16 22:00:42 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	gap;
	int	*arr;
	int	i;

	*range = NULL;
	i = 0;
	if (min >= max)
	{
		return (0);
	}
	gap = max - min;
	arr = (int *)malloc(gap * sizeof(int));
	if (arr == NULL)
		return (-1);
	while (i < gap)
	{
		arr[i] = min;
		i++;
		min++;
	}
	*range = arr;
	return (gap);
}
