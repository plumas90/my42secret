/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:00:59 by minpark           #+#    #+#             */
/*   Updated: 2024/10/05 17:03:55 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	temp;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		temp = 0;
		if (needle[temp] == haystack[i + temp])
		{
			while (needle[temp] && haystack[i + temp])
			{
				if (needle[temp] != haystack[i + temp] || \
					(temp + i) >= len)
					break ;
				temp++;
			}
			if (needle[temp] == '\0')
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (0);
}
