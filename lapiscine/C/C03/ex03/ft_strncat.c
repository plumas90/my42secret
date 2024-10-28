/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:31:18 by minpark           #+#    #+#             */
/*   Updated: 2024/07/05 19:58:58 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (dest[i] != '\0')
	{
		++i;
	}
	while (*src != '\0' && j < nb)
	{
		dest[i] = *src;
		src++;
		++i;
		++j;
	}
	dest[i] = '\0';
	return (dest);
}
