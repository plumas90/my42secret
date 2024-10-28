/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:22:32 by minpark           #+#    #+#             */
/*   Updated: 2024/07/04 17:19:29 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
		}
		else if(str[i] >= 'a' && str[i] <= 'z')
		{
		}
		else
		{
			return (0);
		}
		++i;
	}
	return (1);
}

int main()
{
	char a2;
	char b2;

	a2 = ft_str_is_alpha("hi") + '0' ;
	b2 = ft_str_is_alpha("0") + '0';

	write(1, &a2, 1);
	write(1, "\n" ,1);
	write(1, &b2, 1);
	
}
