/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:23:53 by minpark           #+#    #+#             */
/*   Updated: 2024/07/02 17:27:11 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	endline(void);

void	makerow(int try, char a, char b, char c)
{
	int	i;

	i = 1;
	while (i <= try)
	{
		if (i == 1)
			ft_putchar(a);
		else
		{
			if (i < try)
			{
				ft_putchar(b);
			}
			else
			{
				ft_putchar(c);
			}
		}	
		i++;
	}
	ft_putchar('\n');
}

void	rush(int num1, int num2)
{
	int	row;

	if (num1 <= 0 || num2 <= 0)
	{
		return ;
	}
	row = num2 - 2;
	makerow(num1, 'A', 'B', 'C');
	while (row > 0)
	{
		makerow(num1, 'B', ' ', 'B');
		row--;
	}
	if (num2 >= 2)
	{
		makerow(num1, 'A', 'B', 'C');
	}
}

void	endline(void)
{
	write(1, "\n", 1);
}
