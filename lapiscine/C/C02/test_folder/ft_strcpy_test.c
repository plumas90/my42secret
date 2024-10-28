/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:30:49 by minpark           #+#    #+#             */
/*   Updated: 2024/07/03 15:38:09 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char *ft_strcpy(char *dest, char *src)
{
	*dest = *src + '\0' ;
}

int main()
{
	char* abc;
	char a;

	a = 'c';
	abc = &a;

	*ft_strcpy(abc , "h");

	write(1, abc, 1);
}
