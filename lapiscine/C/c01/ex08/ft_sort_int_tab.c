/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_soft_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:12:34 by minpark           #+#    #+#             */
/*   Updated: 2024/07/03 19:19:25 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	try;
	int	try2;
	int	temp;

	try = 0;
	try2 = 0;
	while (try < size - 1)
	{
		while (try2 < size - 1 - try)
		{
			if (tab[try2] > tab[try2 + 1])
			{
				temp = tab[try2 + 1];
				tab[try2 + 1] = tab[try2];
				tab[try2] = temp;
			}
			try2++;
		}
		try++;
		try2 = 0;
	}
}
