/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:16:01 by minpark           #+#    #+#             */
/*   Updated: 2024/07/09 12:58:09 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = 1;
	if (nb < 0 || power < 0)
		return (0);
	if (power == 0)
	{
		return (i);
	}
	while (power >= 1)
	{
		i *= nb;
		power--;
	}
	return (i);
}
