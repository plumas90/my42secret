/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:45:30 by minpark           #+#    #+#             */
/*   Updated: 2024/07/10 22:36:19 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	str_c(char *a, char *me);

int	length(char *base, char *realbase)
{
	int	i;

	i = 0;
	while (*base)
	{
		if ((*base >= 9 && *base <= 13) || *base == ' ')
		{
			if (!((str_c("\v\t\n\f\r -+", base + 1) || str_c(realbase, base + 1))))
			{
				return (-1);
			}
		}
		else if (*base == '+' || *base == '-')
		{
			if (!(str_c(realbase, base + 1) || (str_c("+-", base + 1))))
				return (-1);
		}
		++i;
		++base;
	}
	return (i);
}

int	duplication(char *cha)
{
	int	i;
	int	j;

	i = 0;
	while (cha[i] != '\0')
	{
		j = i + 1;
		if (str_c("\v\t\n\f\r +-", &cha[i]))
		{
			return (-1);
		}
		while (cha[j] != '\0')
		{
			if (cha[i] == cha[j])
			{
				return (-1);
			}
			++j;
		}
		++i;
	}
	return (i);
}

int	i_to_arr(char *str, int length, char *base, int *check)
{
	int	j;
	int	num;

	num = 0;
	while (*str)
	{
		while (str_c("\v\t\n\f\r -+", str) && *str && num <= 0)
		{
			if (*str == '-')
				*check += 1;
			str++;
		}
		j = 0;
		while (base[j] != '\0' && *str != base[j])
			j++;
		if (*str == base[j])
		{
			num = num * length + j;
		}
		else
			break ;
		str++;
	}
	return (num);
}

int	str_c(char *a, char *me)
{
	while (*a)
	{
		if (*a == *me)
			return (1);
		++a;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nb;
	int	dupl;
	int	answer;
	int	minus_check;

	minus_check = 0;
	nb = 0;
	if (length(str, base) < 0)
		return (0);
	if (base[0] == '\0' || (base[0] != '\0' && base[1] == '\0'))
		return (0);
	dupl = duplication(base);
	if (dupl == -1)
		return (0);
	answer = i_to_arr(str, dupl, base, &minus_check);
	if (minus_check % 2 == 0)
		return (answer);
	return (-answer);
}
