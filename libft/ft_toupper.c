/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:56:02 by minpark           #+#    #+#             */
/*   Updated: 2024/10/01 15:10:23 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int i)
{
	if ('a' <= i && i <= 'z')
	{
		i -= 32;
	}
	return (i);
}
