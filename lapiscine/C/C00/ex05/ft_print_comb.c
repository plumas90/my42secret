/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 12:27:48 by minpark           #+#    #+#             */
/*   Updated: 2024/07/02 17:51:40 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	changechar(int i)
{
	char	c;

	c = '0' + i;
	write(1, &c, 1);
}

void	consolecheck(int i, int j, int k)
{
	if (i == 7 && j == 8 && k == 9)
	{
	}
	else
	{
		write (1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i <= 7)
	{
		j = i + 1;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				changechar(i);
				changechar(j);
				changechar(k);
				consolecheck(i, j, k);
				++k;
			}
			++j;
		}
		++i;
	}
}
