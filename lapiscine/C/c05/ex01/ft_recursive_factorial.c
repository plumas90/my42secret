/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:06:04 by minpark           #+#    #+#             */
/*   Updated: 2024/07/09 13:06:30 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	i;

	if (nb < 0)
	{
		return (0);
	}
	i = 0;
	if (nb > 1)
	{
		i = nb * ft_recursive_factorial(nb - 1);
	}
	else
	{
		i = 1;
	}
	return (i);
}
