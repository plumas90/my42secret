/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:40:14 by minpark           #+#    #+#             */
/*   Updated: 2024/11/13 21:09:11 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_pushswap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	check_int_range(long long number)
{
	if (number < -2147483648 || number > 2147483647)
		return (1);
	return (0);
}

long long	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && (str_c("\t\n\v\f\r +", str[i])))
		i++;
	while (str[i] && str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{	
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
