/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:33:17 by minpark           #+#    #+#             */
/*   Updated: 2024/10/05 16:22:17 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	leng_d;
	size_t	leng_s;

	i = ft_strlen(dest);
	j = 0;
	leng_d = ft_strlen(dest);
	leng_s = ft_strlen(src);
	if (size <= leng_d)
		return (leng_s + size);
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < leng_d)
		return (leng_s + size);
	else
		return (leng_d + leng_s);
}
