/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_voidptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:23:00 by minpark           #+#    #+#             */
/*   Updated: 2024/10/10 21:20:37 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include "ft_printf.h"

int	hexa_addr(unsigned long long addr, int count)
{
	char		*hexa;
	int			i;

	i = count;
	hexa = "0123456789abcdef";
	if (addr > 0)
	{
		count = hexa_addr(addr / 16, i + 1);
		write(1, &hexa[addr % 16], 1);
	}
	return (count);
}

int	ft_print_voidptr(void *str)
{
	int	count;

	if (str == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 2;
	write(1, "0x", 2);
	count = hexa_addr((unsigned long long)(str), count);
	return (count);
}
