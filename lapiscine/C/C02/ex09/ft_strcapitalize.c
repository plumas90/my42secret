/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:30:28 by minpark           #+#    #+#             */
/*   Updated: 2024/07/19 14:21:17 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	file_type(char *str);

char	*ft_strcapitalize(char *str)
{
	int	type;
	int	i;

	i = 0;
	if (file_type(&str[i]) == 1)
		str[i] -= 32;
	i = 1;
	while (str[i] != '\0')
	{
		type = file_type(&str[i]);
		if (type == 0)
		{
			if (file_type(&str[i - 1]) < 4)
				str[i] += 32;
		}
		else if (type == 1)
		{
			if (file_type(&str[i - 1]) == 4)
				str[i] -= 32;
		}
		++i;
	}
	return (str);
}

int	file_type(char *str)
{
	if (*str >= 'A' && *str <= 'Z')
	{
		return (0);
	}
	else if (*str >= 'a' && *str <= 'z')
	{
		return (1);
	}
	else if (*str >= '0' && *str <= '9')
	{
		return (2);
	}
	else
	{
		return (4);
	}
}