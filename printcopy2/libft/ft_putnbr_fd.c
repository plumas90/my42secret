/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:55:39 by minpark           #+#    #+#             */
/*   Updated: 2024/10/05 15:53:51 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	goin(int i, int fd)
{
	char	cha;
	int		tem1;
	int		tem2;

	tem1 = i;
	tem2 = tem1 / 10;
	cha = '0' + (tem1 % 10);
	if (tem2 > 0)
	{
		goin(tem2, fd);
	}
	write(fd, &cha, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	temp;

	if (n == -2147483648)
	{	
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		temp = -n;
	}
	else
	{
		temp = n;
	}
	goin(temp, fd);
}
