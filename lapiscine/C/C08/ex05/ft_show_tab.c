/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:57:36 by minpark           #+#    #+#             */
/*   Updated: 2024/07/14 20:01:53 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_stock_str.h"

void	put_num(int num)
{
	char	a;

	if (num < 0)
	{
		write(1, "-", 1);
		put_num(-(num / 10));
		put_num(-(num % 10));
	}
	else if (num >= 10)
	{
		put_num(num / 10);
		put_num(num % 10);
	}
	else
	{
		a = num + '0';
		write(1, &a, 1);
	}
}

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		++i;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		put_str(par[i].str);
		write(1, "\n", 1);
		put_num(par[i].size);
		write(1, "\n", 1);
		put_str(par[i].copy);
		write(1, "\n", 1);
		++i;
	}
}
