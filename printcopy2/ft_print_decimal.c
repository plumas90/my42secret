/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:14:47 by minpark           #+#    #+#             */
/*   Updated: 2024/10/10 20:12:55 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_decimal(int n)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_itoa(n);
	count = ft_strlen(str);
	write(1, str, count);
	free (str);
	return (count);
}
