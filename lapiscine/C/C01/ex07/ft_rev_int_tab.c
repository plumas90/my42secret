/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:52:41 by minpark           #+#    #+#             */
/*   Updated: 2024/07/03 19:23:45 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	try;
	int	temp;

	try = 0;
	while (try < size / 2)
	{
		temp = tab[0 + try];
		tab[0 + try] = tab[size - 1 - try];
		tab[size - 1 - try] = temp;
		++try;
	}
}
