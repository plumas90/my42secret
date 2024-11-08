/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:27:18 by minpark           #+#    #+#             */
/*   Updated: 2024/11/04 16:27:39 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

size_t	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		s1_length;
	size_t		s2_length;
	int			i;
	int			j;

	j = 0;
	i = 0;
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (s1_length + s2_length + 1));
	if (str == NULL)
		return (0);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

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

char	*ft_strdup(const char *src)
{
	char	*makesrc;
	int		leng;
	int		i;

	i = 0;
	leng = ft_strlen(src);
	makesrc = (char *)malloc(leng + 1);
	if (makesrc == NULL)
	{
		return (NULL);
	}
	while (src[i])
	{
		makesrc[i] = src[i];
		++i;
	}
	makesrc[i] = '\0';
	return (makesrc);
}
