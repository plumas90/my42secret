/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:58:17 by minpark           #+#    #+#             */
/*   Updated: 2024/07/03 17:05:23 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			return (1);
		}
		++i;
	}
	return (0);
}

int main()
{
	int a;
	int b;

	char a2;
	char b2;

	a2 = ft_str_is_numeric("111111") + '0' ;
	b2 = ft_str_is_numeric("a") + '0' ;


	        write(1, &a2, 1);
        write(1, "\n" ,1);
        write(1, &b2, 1);


}
