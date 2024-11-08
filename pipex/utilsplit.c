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

static int	str_c(char a, char me)
{
	if (a == me)
		return (1);
	return (0);
}

static int	c_w(char const *str, char charset, int i)
{
	int	k;

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

static char	*in_info(char const *str, char charset)
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

static char	**ft_freeall(char **list)
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

char	**ft_split(char const *str, char charset)
{
	int		k;
	int		ready;
	char	**coll;

	ready = 1;
	k = 0;
	coll = (char **) malloc ((c_w(str, charset, 0) + 1) * sizeof(char *));
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
