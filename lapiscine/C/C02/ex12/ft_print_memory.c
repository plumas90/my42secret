/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:23:12 by minpark           #+#    #+#             */
/*   Updated: 2024/07/19 15:46:43 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	hexa_addr(long long addr)
{
	char		*hexa;

	hexa = "0123456789abcdef";
	if (addr >= 16)
	{
		hexa_addr(addr / 16);
		write(1, &hexa[addr % 16], 1);
	}
	else
	{
		write(1, &hexa[addr % 16], 1);
	}
}

void	addr_chat(long long addr)
{
	int			i;
	long long	arr;

	arr = addr;
	i = 0;
	while (i < 16)
	{
		if (arr < 16)
			write(1, "0", 1);
		arr /= 16;
		++i;
	}
	hexa_addr(addr);
}

void	ten_six_chat(char *addr)
{
	char	null_check;
	char	*hexa;
	int		i;

	null_check = 0;
	hexa = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		if (addr[i] != '\0' && null_check == 0)
		{
			write(1, &hexa[(unsigned char)addr[i] / 16], 1);
			write(1, &hexa[(unsigned char)addr[i] % 16], 1);
		}
		else
		{
			write(1, "  ", 2);
			null_check = 1;
		}
		++i;
		if (i % 2 == 0)
			write(1, " ", 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (str[i] >= ' ' && str[i] <= '~')
			write(1, &str[i], 1);
		else if (str[i])
		{
			write(1, ".", 1);
		}
		++i;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	char			*arr;

	arr = (char *)addr;
	i = 0;
	if (size == 0)
		return (addr);
	while (i < size)
	{
		addr_chat((long long)(addr + i));
		write(1, ": ", 2);
		ten_six_chat(&arr[i]);
		ft_putstr_non_printable(&arr[i]);
		i += 16;
	}
	return (addr);
}
