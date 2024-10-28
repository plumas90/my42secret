/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:23:12 by minpark           #+#    #+#             */
/*   Updated: 2024/07/05 19:40:18 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	chat(char *arr)
{
	while (*arr != '\0')
	{
		write(1, arr, 1);
		arr++;
	}
}

void	addr_chat(void *addr)
{
	int		i;
	char	a;

	i = (int)addr;
	a = i + '0';
	chat(a);
	write(1, ": ", 2);
}

void	ten_six_chat(char *addr)
{
	char		a;
	char*			addr_temp;
	int				i;

	i = 0;
	addr_temp = addr;
	while (i < 8)
	{
		if (addr_temp != '\0')
		{
			a = addr_temp / 16;
			write(1, &a, 1);
			a = addr_temp % 16;
			write(1, &a, 1);
			addr_temp++;
			a = addr_temp / 16;
			write(1, &a, 1);
			a = addr_temp % 16;
			write(1, &a, 1);
			write(1, ", ", 2);
			addr_temp++;
		}
		++i;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int	i;
	char*		addr2;

	addr2 = (char *)addr;
	i = 0;
	if (size == 0)
	{
		return (0);
	}
	while (*addr2 != '\0')
	{
		addr_chat(addr2);
		ten_six_chat(addr2);
		while (i < 16 && *addr2 != '\0')
		{
			if (*addr2 >= ' ' && *addr2 <= '~' )
			{
				write(1, addr2, 1);
			}
			else
			{
				write(1, ".", 1);
			}
			++i;
			++addr2;
		}
	}
}
