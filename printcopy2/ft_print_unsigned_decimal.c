/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:25:11 by minpark           #+#    #+#             */
/*   Updated: 2024/10/10 21:22:21 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	countnum(unsigned int n)
{
	unsigned int		num;
	int					i;

	num = n;
	i = 0;
	if (n == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa2(unsigned int n)
{
	char		*str;
	long		number;
	int			i;

	number = (long)n;
	i = countnum(n) - 1;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (str == 0)
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		str[i] = (number % 10) + '0';
		number = number / 10;
		i--;
	}
	return (str);
}

int	ft_print_unsigned_decimal(unsigned int n)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_itoa2(n);
	count = ft_strlen(str);
	write(1, str, count);
	free (str);
	return (count);
}
