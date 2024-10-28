/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:36:02 by minpark           #+#    #+#             */
/*   Updated: 2024/10/05 18:03:53 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*dst2;
	unsigned char	*src2;

	dst2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (dst2 < src2)
	{
		i = -1;
		while (++i < (int)n)
		{
			dst2[i] = src2[i];
		}
	}
	else
	{
		i = (int)n;
		while (i--)
		{
			dst2[i] = src2[i];
		}
	}
	return (dest);
}
