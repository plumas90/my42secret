/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:29:15 by minpark           #+#    #+#             */
/*   Updated: 2024/07/17 11:41:00 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_c(char *str, char me)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == me)
			return (1);
		++i;
	}
	return (0);
}

int	find_base_index(char *str, char me)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == me)
			return (i);
		++i;
	}
	return (-1);
}

int	length(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		i++;
	}
	return (i);
}
