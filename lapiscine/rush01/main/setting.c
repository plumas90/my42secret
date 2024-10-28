/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:50:40 by minpark           #+#    #+#             */
/*   Updated: 2024/07/10 14:05:48 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	zero_check(int num);

void	set_zero(int *arr)
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
			arr[i * 4 + j] = '0';
			++j;
		}
		++i;
	}
}

int	last_check(int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (zero_check(arr[i * 4 + j]))
				return (1);
			++j;
		}
		++i;
		arr++;
	}
	return (0);
}

int	value_set(char *argv, int *value)
{
	int	i;

	i = 0;
	while (*argv)
	{
		if (*argv >= '0' && *argv <= '9')
		{
			*value = *argv - '0';
			value++;
			i++;
		}
		argv++;
	}
	if (i != 16)
	{
		return (1);
	}
	return (0);
}
