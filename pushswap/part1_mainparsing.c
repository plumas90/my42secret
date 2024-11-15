/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1_mainparsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:38:14 by minpark           #+#    #+#             */
/*   Updated: 2024/11/13 21:09:11 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_pushswap.h"

void	duplicate_check(int *result)
{
	int	i;
	int	j;
	int	index;

	i = 1;
	index = 0;
	while (index < result[0])
	{
		j = i + 1;
		while (result[j] != 0)
		{
			if (result[i] == result[j])
			{
				write(1, "Error\n", 6);
				exit (1);
			}
			j++;
		}
		i++;
		index++;
	}
}

void	atoi_array(int *result, char **temp, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{	
		if (check_int_range(ft_atoi(temp[i])))
		{
			write(2, "Error\n", 6);
			free(result);
			ft_freeall(temp);
			exit(1);
		}
		result[i + 1] = ft_atoi(temp[i]);
		i++;
	}
	result[i + 1] = 0;
	ft_freeall(temp);
	temp = NULL;
}

int	*parsing_argv(int argc, char **argv)
{
	int		split_size;
	int		*result;
	char	**temp;

	if (argc <= 1)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	check_argv(argv);
	temp = ft_split2(argc, argv, 1);
	if (temp == NULL)
		exit(1);
	split_size = 0;
	while (temp[split_size])
		split_size++;
	result = (int *)malloc(sizeof(int) * (split_size + 2));
	if (result == NULL)
		exit(1);
	result[0] = split_size;
	atoi_array(result, temp, split_size);
	duplicate_check(result);
	return (result);
}
