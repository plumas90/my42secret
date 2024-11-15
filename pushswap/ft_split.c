/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:03:30 by minpark           #+#    #+#             */
/*   Updated: 2024/11/13 21:09:11 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_pushswap.h"

int	str_c(char *a, char me)
{
	while (*a)
	{
		if (*a == me)
			return (1);
		++a;
	}
	return (0);
}

int	c_w(char const *str, char *charset)
{
	int	k;
	int	i;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (str_c(charset, str[i]) && str[i])
			i++;
		if (str[i])
			++k;
		while (!str_c(charset, str[i]) && str[i])
			i++;
	}
	return (k);
}

static char	*in_info(char const *str, char *charset)
{
	int		i;
	char	*coll;

	i = 0;
	while (!str_c(charset, str[i]) && str[i])
		i++;
	coll = (char *)malloc(i * sizeof(char) + 1);
	if (coll == NULL)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (!str_c(charset, *str) && *str)
		{
			coll[i] = *str;
			str++;
			i++;
		}
		break ;
	}
	coll[i] = '\0';
	return (coll);
}

char	**ft_freeall(char **list)
{
	size_t	j;

	j = 0;
	while (list[j])
	{
		free(list[j]);
		j++;
	}
	free(list);
	return (NULL);
}

char	**ft_split(char *str, char *charset)
{
	int		k;
	int		ready;
	char	**coll;

	ready = 1;
	k = 0;
	coll = (char **) malloc ((c_w(str, charset) + 1) * sizeof(char *));
	while (*str)
	{	
		if (!str_c(charset, *str) && *str && ready == 1)
		{
			coll[k++] = in_info(str, charset);
			if (coll[k - 1] == NULL)
				ft_freeall(coll);
			ready = 0;
		}
		else if (str_c(charset, *str) && *str)
			ready = 1;
		str++;
	}
	coll[k] = NULL;
	return (coll);
}
