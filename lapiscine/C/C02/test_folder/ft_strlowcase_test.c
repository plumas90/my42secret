/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:53:54 by minpark           #+#    #+#             */
/*   Updated: 2024/07/03 18:57:16 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char *ft_strlowcase(char *str)
{
        int     i;
        i = 0;

        while(str[i] != '\0')
        {
                if(str[i] >= 'A' && str[i] <= 'Z')
                {
                        str[i] +=  32;
                }
                ++i;
        }
}


int main()
{
        char a[4];
        a[0] = 'A';
        a[1] = '1';
        a[2] = '`';
       	a[3] = 'S';

        *ft_strlowcase(a);

        write(1, &a[0] , 1);
        write(1, &a[1] , 1);
        write(1, &a[2] , 1);
        write(1, &a[3] , 1);

}
