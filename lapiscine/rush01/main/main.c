/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:37:32 by minpark           #+#    #+#             */
/*   Updated: 2024/07/10 14:10:12 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		value_set(char *argv, int *value);
int		last_check(int *arr);
int		zero_check(int num);
void	down14(int *argv, int *arr, int i);
void	left14(int *argv, int *arr, int i);
void	ch_zero(int *arr);
void	up13(int *argv, int *arr, int i);
void	up24(int *argv, int *arr, int i);
void	right13(int *argv, int *arr, int i);
void	right24(int *argv, int *arr, int i);
void	set_zero(int *arr);

int	zero_check(int num)
{
	if (num == '0')
	{
		return (1);
	}
	return (0);
}

void	printarr(int *arr)
{	
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, &arr[i * 4 + j], 1);
			if (j < 3)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			++j;
		}
		++i;
	}
}

void	loop(int *value, int *arr)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < 12 && i > 7)
		{
			up13(&value[i], arr, i % 4);
			up24(&value[i], arr, i % 4);
		}
		else if (i < 4)
		{
			right13(&value[i], arr, (i % 4));
			right24(&value[i], arr, (i % 4));
		}
		else if (i >= 4 && i < 8)
		{
			left14(&value[i], arr, (i % 4));
		}
		else if (i >= 12)
		{
			down14(&value[i], arr, i % 4);
		}
		++i;
	}
}

void	lastphase(int *value, int *arr)
{
	loop(value, arr);
	ch_zero(arr);
	ch_zero(arr);
	loop(value, arr);
	ch_zero(arr);
	ch_zero(arr);
	loop(value, arr);
	ch_zero(arr);
	ch_zero(arr);
	loop(value, arr);
	ch_zero(arr);
	ch_zero(arr);
}

int	main(int argc, char **argv)
{
	int	arr[4][4];
	int	value[17];

	if (argc != 2)
	{
		write(1, "error argc\n", 11);
		return (-1);
	}
	if (value_set(argv[1], value))
	{
		write(1, "error value num\n", 16);
		return (-1);
	}
	set_zero(*arr);
	lastphase(value, *arr);
	if (last_check(*arr))
	{	
		write(1, "error\n", 6);
		return (-1);
	}	
	printarr(*arr);
	return (0);
}
