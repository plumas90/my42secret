/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1_check_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:13:17 by minpark           #+#    #+#             */
/*   Updated: 2024/11/13 21:09:11 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_pushswap.h"

int	check_spaces(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j])
		{
			if (str_c("\t\n\v\f\r ", argv[i][j]))
			{
				if (argv[i][j + 1] == 0)
					return (1);
				j++;
			}
			else
			{
				break ;
			}	
		}
		i++;
	}
	return (0);
}

int	check_null(char **argv)
{
	int	i;
	int	leng;

	i = 1;
	while (argv[i])
	{
		leng = ft_strlen(argv[i]);
		if (leng == 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j])
		{
			if (str_c("\t\n\v\f\r +-", argv[i][j]))
				j++;
			else if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

int	check_sign(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			if (str_c("+-", argv[i][j]))
			{
				j++;
				if (argv[i][j] == 0 || str_c("\t\n\v\f\r +-", argv[i][j]))
					return (1);
			}
			else
				j++;
		}
		i++;
	}
	return (0);
}

void	check_argv(char **argv)
{
	if (check_null(argv) || check_spaces(argv)
		|| check_digit(argv) || check_sign(argv))
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	return ;
}
