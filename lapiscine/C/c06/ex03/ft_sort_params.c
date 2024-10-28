/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:47:02 by minpark           #+#    #+#             */
/*   Updated: 2024/07/10 19:59:50 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
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
		i = 1;
		while (i < argc - 1)
		{		
			if (ft_strcmp(argv[i], argv[i + 1]))
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

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	swap(argc, argv);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		++i;
	}
}
