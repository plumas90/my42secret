/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:11:28 by minpark           #+#    #+#             */
/*   Updated: 2024/07/20 16:05:35 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	maxlength(char **strs, int size)
{
	int	i;
	int	j;
	int	all_length;

	all_length = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			all_length++;
			++j;
		}
		++i;
	}
	return (all_length);
}

int	leng(char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = -1;
	if (size == 0)
	{
		arr = (char *)malloc(1 * sizeof(char));
		arr[0] = '\0';
		return (arr);
	}
	arr = (char *)malloc(maxlength(strs, size) + ((size - 1) * leng(sep)) + 1);
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
			arr[k++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < size -1)
			arr[k++] = sep[j++];
	}
	arr[k] = '\0';
	return (arr);
}
