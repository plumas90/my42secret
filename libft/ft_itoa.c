/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:51:21 by minpark           #+#    #+#             */
/*   Updated: 2024/10/04 16:27:22 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>

static int	countnum(int n)
{
	long	num;
	int		i;

	num = n;
	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		num *= -1;
	}
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	long		number;
	int			i;

	number = (long)n;
	i = countnum(n) - 1;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (str == 0)
		return (NULL);
	if (n == -2147483648)
		number = 2147483648;
	else if (number < 0)
		number *= -1;
	str[i + 1] = '\0';
	while (i >= 0)
	{
		str[i] = (number % 10) + '0';
		number = number / 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
