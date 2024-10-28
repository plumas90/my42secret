/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:20:14 by minpark           #+#    #+#             */
/*   Updated: 2024/07/03 18:52:23 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char *ft_strupcase(char *str)
{
	int	i;
	i = 0;

	while(str[i] != '\0')
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -=  32;
		}
		++i;
	}
}

int main()
{
	char a[4];
	a[0] = 'a';
	a[1] = '1';
	a[2] = '`';
	a[3] = 's';

	*ft_strupcase(a);

	write(1, &a[0] , 1);
	write(1, &a[1] , 1);
	write(1, &a[2] , 1);
	write(1, &a[3] , 1);

}
