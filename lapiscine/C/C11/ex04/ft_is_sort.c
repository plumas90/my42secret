/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:58:37 by minpark           #+#    #+#             */
/*   Updated: 2024/07/18 20:14:37 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	up;
	int	down;

	up = 0;
	down = 0;
	i = 0;
	if (length <= 1)
		return (1);
	while (i < length - 1)
	{
		if (((*f)(tab[i], tab[i + 1])) >= 0)
			down++;
		if (((*f)(tab[i], tab[i + 1])) <= 0)
			up++;
		++i;
	}
	if (up == length -1 || down == length - 1)
	{
		return (1);
	}
	else
		return (0);
}
