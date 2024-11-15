/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:08:01 by minpark           #+#    #+#             */
/*   Updated: 2024/07/02 14:46:23 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	goin(int i)
{
	char	cha;
	int		tem1;
	int		tem2;

	tem1 = i;
	tem2 = tem1 / 10;
	cha = '0' + (tem1 % 10);
	if (tem2 > 0)
	{
		goin(tem2);
	}
	write(1, &cha, 1);
}

void	ft_putnbr(int nb)
{
	int	temp;

	if (nb == -2147483648)
	{	
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		temp = -nb;
	}
	else
	{
		temp = nb;
	}
	goin(temp);
}
