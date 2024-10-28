/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findright.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:20:05 by minpark           #+#    #+#             */
/*   Updated: 2024/07/10 13:30:32 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	right13(int *argv, int *arr, int i)
{
	if (*argv == 1)
	{
		arr[0 * 4 + i] = '4';
		if (*(argv + 4) == 3)
		{
			arr[i + 4 * 2] = '3';
		}
	}
	else if (*argv == 3)
	{
		if (*(argv + 4) == 2)
		{
			arr[i + 2 * 4] = '4';
			if (arr[i + 4 * 3] != '0' && arr[i + 4 * 3] != '1')
				arr[i + 4 * 0] = '1';
			else if (arr[i + 4 * 0] != '0' && arr[i + 4 * 0] != '1')
				arr[i + 4 * 3] = '1';
		}
	}
}

void	right24(int *argv, int *arr, int i)
{
	if (*argv == 2)
	{
		if (*(argv + 4) == 2)
		{
			if (arr[3 * 4 + i] != '0' && arr[3 * 4 + i] != '3')
				arr[0 * 4 + i] = '3';
			else if (arr[3 * 4 + i] != '0' && arr[3 * 4 + i] != '3')
				arr[3 * 4 + i] = '3';
		}
		else if (*(argv + 4) == 3)
		{
			if (arr[3 * 4 + i] != '0' && arr[3 * 4 + i] != '1')
				arr[0 * 4 + i] = '1';
			else if (arr[0 * 4 + i] != '0' && arr[0 * 4 + i] != '1')
				arr[3 * 4 + i] = '1';
		}
	}
	else if (*argv == 4)
	{
		arr[0 * 4 + i] = '1';
		arr[1 * 4 + i] = '2';
		arr[2 * 4 + i] = '3';
		arr[3 * 4 + i] = '4';
	}
}
