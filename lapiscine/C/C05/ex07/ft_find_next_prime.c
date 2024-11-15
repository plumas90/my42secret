/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:38:40 by minpark           #+#    #+#             */
/*   Updated: 2024/07/09 13:01:46 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_is_prime(int nb);

int	ft_find_next_prime(int nb)
{
	while (1)
	{
		if (ft_is_prime(nb) == 1)
		{
			return (nb);
			break ;
		}
		nb++;
	}
	return (nb);
}

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
	{
		return (0);
	}
	while (i < (nb / 2) + 1)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		++i;
	}
	return (1);
}
