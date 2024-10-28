/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_do-op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:05:33 by minpark           #+#    #+#             */
/*   Updated: 2024/07/16 19:15:57 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	cutnum(int a);

int	setnum(char *str)
{
	int	num;
	int	check;
	int	i;

	i = 0;
	check = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			check *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * check);
}

void	write_num(int answer)
{
	if (answer == -2147483648)
	{
		write(1, "-", 1);
		cutnum(-(answer / 10));
		cutnum(-(answer % 10));
	}
	else if (answer < 0)
	{
		write(1, "-", 1);
		cutnum(-answer);
	}
	else
	{
		cutnum(answer);
	}
	write(1, "\n", 1);
}

void	check_write(int i, int *check)
{
	if (i == 0)
	{
		*check = 2;
	}
	else if (i == 1)
	{
		write(1, "Stop : division by zero\n", 24);
		*check = 1;
	}
	else if (i == 2)
	{
		write(1, "Stop : modulo by zero\n", 22);
		*check = 1;
	}
}

void	check_dustks(char **argv, int *left, int *right, int *check)
{
	if (argv[2][0] == '+' && argv[2][1] == '\0')
		*left = *left + *right;
	else if (argv[2][0] == '-' && argv[2][1] == '\0')
		*left = *left - *right;
	else if (argv[2][0] == '*' && argv[2][1] == '\0')
		*left = *left * *right;
	else if (argv[2][0] == '/' && argv[2][1] == '\0')
	{
		if (*right == 0)
			check_write(1, check);
		else
			*left = *left / *right;
	}
	else if (argv[2][0] == '%' && argv[2][1] == '\0')
	{
		if (*right == 0)
			check_write(2, check);
		else
			*left = *left % *right;
	}
	else
		check_write(0, check);
}

int	main(int argc, char **argv)
{
	int	left;
	int	right;
	int	check;

	check = 0;
	if (argc != 4)
		return (0);
	left = setnum(argv[1]);
	right = setnum(argv[3]);
	check_dustks(argv, &left, &right, &check);
	if (check == 2)
	{
		write(1, "0", 1);
		write(1, "\n", 1);
		return (0);
	}
	else if (check == 0)
		write_num(left);
	return (0);
}
