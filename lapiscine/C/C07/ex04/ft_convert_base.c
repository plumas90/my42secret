/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:24:29 by minpark           #+#    #+#             */
/*   Updated: 2024/07/20 16:02:56 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

int		length(char *base);
int		str_c(char *str, char me);
int		find_base_index(char *str, char me);

void	tobase(char *base, int nownum, char *arr, int *i)
{
	int	temp;
	int	base_type;

	base_type = length(base);
	temp = nownum;
	if (temp >= base_type)
	{
		temp = temp % base_type;
		nownum = nownum / base_type;
		tobase(base, nownum, arr, i);
		arr[*i] = base[temp];
		*i += 1;
	}
	else
	{
		arr[*i] = base[nownum % base_type];
		*i += 1;
	}
}

int	my_atoi(char *nbr, char *base_from)
{
	int	return_num;
	int	minus_c;
	int	i;

	i = 0;
	minus_c = 1;
	return_num = 0;
	while (str_c("\v\t\n\f\r ", nbr[i]) && nbr[i])
		i++;
	while (str_c("+-", nbr[i]) && nbr[i])
	{
		if (nbr[i] == '-')
			minus_c *= -1;
		i++;
	}
	while (nbr[i])
	{
		if (str_c(base_from, nbr[i]))
			return_num = return_num * length(base_from) \
				+ find_base_index(base_from, nbr[i]);
		else
			break ;
		++i;
	}
	return (return_num * minus_c);
}

int	check_base(char *base_to)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base_to[i])
	{
		if (str_c("\v\t\n\f\r-+ ", base_to[i]))
			return (1);
		j = i + 1;
		while (base_to[j] != '\0')
		{
			if (base_to[i] == base_to[j])
			{
				return (-1);
			}
			++j;
		}
		++i;
	}
	if (i <= 1)
		return (1);
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result_arr;
	int		atoi_nbr;
	int		i;

	i = 0;
	if (check_base(base_from) || check_base(base_to))
		return (0);
	atoi_nbr = my_atoi(nbr, base_from);
	result_arr = (char *)malloc(34);
	if (atoi_nbr < 0)
	{
		i = 1;
		result_arr[0] = '-';
		tobase(base_to, -(atoi_nbr / length(base_to)), result_arr, &i);
		tobase(base_to, -(atoi_nbr % length(base_to)), result_arr, &i);
	}
	else
		tobase(base_to, atoi_nbr, result_arr, &i);
	result_arr[i] = '\0';
	return (result_arr);
}
