/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:58:45 by minpark           #+#    #+#             */
/*   Updated: 2024/07/09 12:58:44 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	i;

	i = 1;
	if (nb < 0 || power < 0)
		return (0);
	if (power == 0)
	{
		return (i);
	}
	i = nb * ft_recursive_power(nb, power - 1);
	return (i);
}
