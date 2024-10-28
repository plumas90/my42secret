/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:50:24 by minpark           #+#    #+#             */
/*   Updated: 2024/10/04 16:58:36 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char		*answer;
	size_t				i;

	answer = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		answer[i] = 0;
		i++;
	}
}
