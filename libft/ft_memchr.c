/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:07:49 by minpark           #+#    #+#             */
/*   Updated: 2024/10/04 17:05:22 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*pb;

	pb = (unsigned char *)s;
	while (n > 0)
	{
		if (*pb == (unsigned char)c)
			return ((void *)pb);
		pb++;
		n--;
	}
	return (0);
}
