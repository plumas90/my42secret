/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:29:53 by minpark           #+#    #+#             */
/*   Updated: 2024/10/10 21:07:39 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_isalpha2(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (2);
	}
	else if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	return (0);
}

int	need_space(unsigned int num)
{
	int	i;

	i = 1;
	while (num >= 16)
	{
		num /= 16;
		++i;
	}
	return (i);
}

char	*ten_six_chat(unsigned int num)
{
	char	*hexa;
	char	*str;
	int		i;

	hexa = "0123456789abcdef";
	i = need_space(num);
	str = (char *) malloc (sizeof(char) *(i + 1));
	if (str == NULL)
		return (0);
	str[i--] = '\0';
	while (num >= 16)
	{
		str[i] = hexa[num % 16];
		num /= 16;
		i--;
	}
	str[i] = hexa[num % 16];
	return (str);
}

int	ft_print_hex(unsigned int num, char src)
{
	char	*str;
	int		count;
	int		i;

	i = 0;
	count = 0;
	str = ten_six_chat(num);
	if (src == 'X')
	{
		while (str[i] != '\0')
		{
			if ('a' <= str[i] && str[i] <= 'z')
				str[i] -= 32;
			i++;
		}
	}
	ft_putstr_fd(str, 1);
	count = ft_strlen(str);
	free(str);
	return (count);
}
