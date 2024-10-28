/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:45:53 by minpark           #+#    #+#             */
/*   Updated: 2024/07/02 17:46:26 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	jump(void)
{
	write(1, " ", 1);
}

void	consolecheck(int i, int j)
{
	if (i == 98 && j == 99)
	{
	}	
	else
	{
		write(1, ", ", 2);
	}
}

void	cutandwrite(int i)
{
	char	ten;
	char	one;

	ten = '0' + i / 10;
	one = '0' + i % 10;
	write(1, &ten, 1);
	write(1, &one, 1);
}

void	ft_print_comb2(void)
{
	int	firstnum;
	int	secondnum;

	firstnum = 0;
	secondnum = 0;
	while (firstnum <= 98)
	{
		secondnum = firstnum + 1;
		while (secondnum <= 99)
		{
			cutandwrite(firstnum);
			jump();
			cutandwrite(secondnum);
			consolecheck(firstnum, secondnum);
			++secondnum;
		}
		++firstnum;
	}
}
