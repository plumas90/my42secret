/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:54:50 by minpark           #+#    #+#             */
/*   Updated: 2024/10/10 14:15:15 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include "ft_printf.h"

int	ft_print_char(int c);
int	ft_print_str(char *s);
int	ft_print_voidptr(void *ptr);
int	ft_print_decimal(int d);
int	ft_print_unsigned_decimal(unsigned int u);
int	ft_print_hex(unsigned int hex, char chr);

int	ft_type_check(va_list lst, char src)
{
	int	count;

	count = 0;
	if (src == 'c')
		count = ft_print_char(va_arg(lst, int));
	else if (src == 's')
		count = ft_print_str(va_arg(lst, char *));
	else if (src == 'p')
		count = ft_print_voidptr(va_arg(lst, void *));
	else if (src == 'd' || src == 'i')
		count = ft_print_decimal(va_arg(lst, int));
	else if (src == 'u')
		count = ft_print_unsigned_decimal(va_arg(lst, unsigned int));
	else if (src == 'x' || src == 'X')
		count = ft_print_hex(va_arg(lst, unsigned int), src);
	else
		count = write(1, &src, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	va_lst;

	if (str == NULL)
		return (0);
	i = 0;
	len = 0;
	va_start(va_lst, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_type_check(va_lst, str[i]);
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(va_lst);
	return (len);
}
