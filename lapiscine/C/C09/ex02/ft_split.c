/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:03:30 by minpark           #+#    #+#             */
/*   Updated: 2024/07/16 20:30:39 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

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

int	c_w(char *str, char *charset, int i)
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

char	*in_info(char *str, char *charset)
{
	int		i;
	char	*coll;

	i = 0;
	while (str[i])
	{
		while (!str_c(charset, str[i]) && str[i])
			i++;
		break ;
	}
	coll = (char *)malloc(i * sizeof(char) + 1);
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

char	**ft_split(char *str, char *charset)
{
	int		k;
	int		j;
	int		ready;
	char	**coll;

	ready = 1;
	k = 0;
	j = -1;
	coll = (char **) malloc ((c_w(str, charset, 0) + 1) * sizeof(char *));
	while (*str)
	{	
		if (!str_c(charset, *str) && *str)
		{
			if (ready == 1)
			{	
				coll[k++] = in_info(str, charset);
				ready = 0;
			}
		}
		else if (str_c(charset, *str) && *str)
			ready = 1;
		str++;
	}
	coll[k] = NULL;
	return (coll);
}
