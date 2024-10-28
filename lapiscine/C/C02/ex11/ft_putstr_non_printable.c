/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:11:36 by minpark           #+#    #+#             */
/*   Updated: 2024/07/05 21:42:16 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	set_hexa(char *tap)
{
	tap[0] = '0';
	tap[1] = '1';
	tap[2] = '2';
	tap[3] = '3';
	tap[4] = '4';
	tap[5] = '5';
	tap[6] = '6';
	tap[7] = '7';
	tap[8] = '8';
	tap[9] = '9';
	tap[10] = 'a';
	tap[11] = 'b';
	tap[12] = 'c';
	tap[13] = 'd';
	tap[14] = 'e';
	tap[15] = 'f';
}

void	ft_putstr_non_printable(char *str)
{
	int		tmp;
	char	hexadecimal[17];

	set_hexa(hexadecimal);
	while (*str != '\0')
	{
		if (*str >= ' ' && *str <= '~')
			write(1, str, 1);
		else
		{
			write(1, "\\", 1);
			tmp = (unsigned char)*str / 16;
			write(1, &hexadecimal[tmp], 1);
			tmp = (unsigned char)*str % 16;
			write(1, &hexadecimal[tmp], 1);
		}
		str++;
	}
}
