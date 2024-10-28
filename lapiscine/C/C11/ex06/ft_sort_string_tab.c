/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:47:02 by minpark           #+#    #+#             */
/*   Updated: 2024/07/16 16:58:43 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strcmp_jjap(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 > *s2)
		{
			return (1);
		}
		else if (*s1 < *s2)
		{
			return (0);
		}
		++s1;
		++s2;
	}
	return (0);
}

void	swap(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	i = 1;
	while (argc > 0)
	{
		i = 0;
		while (i < argc - 1)
		{		
			if (ft_strcmp_jjap(argv[i], argv[i + 1]))
			{
				temp = argv[i + 1];
				argv[i + 1] = argv[i];
				argv[i] = temp;
			}
			++i;
		}
		argc--;
	}
}

void	ft_sort_string_tab(char **tab)
{
	int	argc;

	argc = 0;
	while (tab[argc])
	{
		argc++;
	}
	swap(argc, tab);
}
