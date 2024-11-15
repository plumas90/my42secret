/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:03:30 by minpark           #+#    #+#             */
/*   Updated: 2024/11/13 21:09:11 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_pushswap.h"

char	**ft_split2(int argc, char **argv, int i)
{
	int		j;
	int		k;
	int		wordcount;
	char	**result;
	char	**temp;

	k = 0;
	j = 0;
	wordcount = 0;
	i = 1;
	while (i < argc)
		wordcount += c_w(argv[i++], "\t\n\v\f\r ");
	i = 1;
	result = (char **)malloc(sizeof(char *) * (wordcount + 1));
	while (i < argc)
	{
		temp = ft_split(argv[i++], "\t\n\v\f\r ");
		j = 0;
		while (temp[j])
			result[k++] = temp[j++];
		free(temp);
	}
	result[k] = NULL;
	return (result);
}
