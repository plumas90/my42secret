/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:35:29 by minpark           #+#    #+#             */
/*   Updated: 2024/07/04 18:10:13 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	length_count(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int		count;
	unsigned int		i;

	count = length_count(src);
	if (size == 0)
	{
		return (count);
	}
	i = 0;
	while (src[i] != '\0' && i < size -1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (count);
}

int main()
{
        char str[61] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
            printf("%s\n", ft_strcapitalize(str));
    return 0;
}


