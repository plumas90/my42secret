/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:13:35 by minpark           #+#    #+#             */
/*   Updated: 2024/10/17 17:47:03 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (&str[i] && str[i] != '\0')
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

int	ft_strchr2(char *str)
{
	char	*strcopy;
	int		i;

	i = 0;
	strcopy = str;
	while (strcopy[i])
	{
		if (strcopy[i] == '\n')
		{
			return (i);
		}
		++i;
	}
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	length;
	char	*sub;

	i = (size_t) start;
	j = 0;
	length = len;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		length = ft_strlen(s) - start;
	sub = (char *)malloc(sizeof(char) * (length + 1));
	if (sub == NULL)
		return (NULL);
	while (s[i])
	{
		if (j < len)
			sub[j++] = s[i];
		i++;
	}
	sub[j] = '\0';
	return (sub);
}
