/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cutcha.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:42:25 by minpark           #+#    #+#             */
/*   Updated: 2024/07/10 14:05:12 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	del(int *a, int c);

void	per1(int num, int *cha, int *arr)
{
	if (num % 4 == 0)
	{
		del(cha, arr[num + 1]);
		del(cha, arr[num + 2]);
		del(cha, arr[num + 3]);
	}
	if (num % 4 == 1)
	{
		del(cha, arr[num + 1]);
		del(cha, arr[num + 2]);
		del(cha, arr[num - 1]);
	}
}

void	per2(int num, int *cha, int *arr)
{
	if (num % 4 == 2)
	{
		del(cha, arr[num + 1]);
		del(cha, arr[num - 1]);
		del(cha, arr[num - 2]);
	}
	if (num % 4 == 3)
	{
		del(cha, arr[num - 1]);
		del(cha, arr[num - 2]);
		del(cha, arr[num - 3]);
	}
}

void	slash1(int num, int *cha, int *arr)
{
	if (num / 4 == 0)
	{
		del(cha, arr[num + 4]);
		del(cha, arr[num + 8]);
		del(cha, arr[num + 12]);
	}
	if (num / 4 == 1)
	{
		del(cha, arr[num + 4]);
		del(cha, arr[num + 8]);
		del(cha, arr[num - 4]);
	}
}

void	slash2(int num, int *cha, int *arr)
{
	if (num / 4 == 2)
	{
		del(cha, arr[num + 4]);
		del(cha, arr[num - 4]);
		del(cha, arr[num - 8]);
	}
	if (num / 4 == 3)
	{
		del(cha, arr[num - 4]);
		del(cha, arr[num - 8]);
		del(cha, arr[num - 12]);
	}
}

void	cha_set(int *cha)
{
	int	i;

	i = 1;
	cha[0] = '1';
	cha[1] = '2';
	cha[2] = '3';
	cha[3] = '4';
	cha[4] = '9';
}
