/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:16:42 by minpark           #+#    #+#             */
/*   Updated: 2024/07/03 18:50:31 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= ' ' && str[i] <= '~')
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
        int a;
        int b;

        char a2;
        char b2;

        a2 = ft_str_is_printable("`````1121212") + '0' ;
        b2 = ft_str_is_printable("abA!@!$@!@#^$#~1`1") + '0';

        write(1, &a2, 1);
        write(1, "\n" ,1);
        write(1, &b2, 1);

}
