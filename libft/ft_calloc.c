/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:01:52 by minpark           #+#    #+#             */
/*   Updated: 2024/10/08 13:57:28 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h> 

void	*ft_calloc(size_t num, size_t size)
{
	char	*temp;
	size_t	i;
	size_t	sum;

	i = 0;
	if (num == 0 || size == 0)
		return (malloc(0));
	if (num > SIZE_MAX / size)
		return (NULL);
	sum = num * size;
	temp = (char *)malloc(num * size);
	if (temp == NULL)
	{
		return (0);
	}
	while (i < sum)
	{
		temp[i] = 0;
		++i;
	}
	return (temp);
}
