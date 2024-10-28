/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:06:37 by minpark           #+#    #+#             */
/*   Updated: 2024/07/13 22:38:10 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

int	length(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		++i;
	}
	return (i);
}

char	*ft_strdup(char	*src)
{
	char	*makesrc;
	int		leng;
	int		i;

	i = 0;
	leng = length(src);
	makesrc = (char *)malloc(leng + 1);
	if (makesrc == NULL)
	{
		return (0);
	}
	while (src[i])
	{
		makesrc[i] = src[i];
		++i;
	}
	makesrc[i] = '\0';
	return (makesrc);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*str;
	int				i;

	i = 0;
	str = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (str == NULL)
	{
		return (0);
	}
	while (i < ac)
	{
		str[i].size = length(av[i]);
		str[i].str = av[i];
		str[i].copy = ft_strdup(av[i]);
		++i;
	}
	str[i].str = 0;
	return (str);
}
