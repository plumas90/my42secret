/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_do-op2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:43:24 by minpark           #+#    #+#             */
/*   Updated: 2024/07/14 14:44:08 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	cutnum(int a)
{
	char	c;

	if (a >= 10)
	{
		cutnum(a / 10);
		a = a % 10;
	}
	c = a + '0';
	write(1, &c, 1);
}
