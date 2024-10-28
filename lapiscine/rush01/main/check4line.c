/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check4line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:02:34 by minpark           #+#    #+#             */
/*   Updated: 2024/07/10 13:46:44 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	cha_set(int *cha);
void	slash2(int num, int *cha, int *arr);
void	slash1(int num, int *cha, int *arr);
void	per1(int num, int *cha, int *arr);
void	per2(int num, int *cha, int *arr);
void	ch_4(int *arr, int num);
int		checkarr(int *numarr);
int		nominus(int *cha);

void	ch_zero(int *arr)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	j = 0;
	num = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (arr[i * 4 + j] == '0')
			{
				ch_4(arr, num);
			}
			num++;
			++j;
		}
		++i;
	}
}

void	del(int *a, int c)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (a[i] == c)
		{
			a[i] = '9';
		}
		++i;
	}
}

void	ch_4(int *arr, int num)
{
	int	numarr[5];
	int	count;

	count = 0;
	cha_set(numarr);
	per1(num, numarr, arr);
	per2(num, numarr, arr);
	slash1(num, numarr, arr);
	slash2(num, numarr, arr);
	count = checkarr(numarr);
	if (count == 1)
	{
		arr[num] = nominus(numarr);
	}
}

int	checkarr(int *numarr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 5)
	{
		if (numarr[i] != '0' && numarr[i] != '9')
		{
			count++;
		}
		i++;
	}
	return (count);
}

int	nominus(int *cha)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (cha[i] != '9')
		{
			return (cha[i]);
		}
		++i;
	}
	return (0);
}
