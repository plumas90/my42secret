/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:11:46 by minpark           #+#    #+#             */
/*   Updated: 2024/07/03 10:36:37 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putout(int nb, int *arr, int firstcheck)
{
	int	i;

	if (firstcheck == 1)
	{
		write(1, ", ", 2);
	}
	i = 0;
	while (i < nb)
	{
		ft_putchar(arr[i] + '0');
		i++;
	}
}

void	increment(int nb, int *arr)
{
	int	i;
	int	max;

	i = nb - 1;
	max = 9;
	while (arr[i] == max)
	{
		i -= 1;
		max -= 1;
	}
	arr[i] += 1;
	while (i < nb)
	{
		arr[i + 1] = arr[i] + 1;
		i += 1;
	}
}

void	ft_print_combn(int nb)
{
	int	arr[10];
	int	i;

	i = 0;
	while (i < nb)
	{
		arr[i] = i;
		i++;
	}
	ft_putout(nb, arr, 0);
	while (arr[0] != 10 - nb || arr[nb - 1] != 9)
	{
		if (arr[nb - 1] != 9)
		{
			arr[nb - 1] += 1;
		}
		else
		{
			increment(nb, arr);
		}
		ft_putout(nb, arr, 1);
	}
}
