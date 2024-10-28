/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:56:14 by minpark           #+#    #+#             */
/*   Updated: 2024/07/03 15:58:30 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	int i;
	i = 0;
	while(i < n)
	{
		dest[i] = src[i];
		write(1, &dest[i] ,1);
		++i;
	}
}

int main()
{
	char a[4];
	*ft_strncpy(a  ,"aaaa" , 4);
}
