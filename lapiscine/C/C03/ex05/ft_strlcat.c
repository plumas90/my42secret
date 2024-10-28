/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:33:17 by minpark           #+#    #+#             */
/*   Updated: 2024/07/12 15:00:38 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	leng_check(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	leng_d;
	unsigned int	leng_s;

	i = leng_check(dest);
	j = 0;
	leng_d = leng_check(dest);
	leng_s = leng_check(src);
	if (size < 1)
		return (leng_s + size);
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < leng_d)
		return (leng_s + size);
	else
		return (leng_d + leng_s);
}
