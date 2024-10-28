/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:50:47 by minpark           #+#    #+#             */
/*   Updated: 2024/10/05 18:18:17 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	while ((*s1 != '\0' || *s2 != '\0') && a < n)
	{
		if ((unsigned char)s1[a] > (unsigned char)s2[a])
		{
			return (1);
		}
		else if ((unsigned char)s1[a] < (unsigned char)s2[a])
		{
			return (-1);
		}
		++a;
	}
	return (0);
}
