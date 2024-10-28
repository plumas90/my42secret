/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:59:27 by minpark           #+#    #+#             */
/*   Updated: 2024/07/08 20:38:40 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	length(char *base)
{
	int	i;

	i = 0;
	while (*base)
	{
		if (*base == '+' || *base == '-')
		{
			return (-1);
		}
		++i;
		++base;
	}
	return (i);
}

int	duplication(char *cha)
{
	int	i;
	int	j;

	i = 0;
	while (cha[i] != '\0')
	{
		j = i + 1;
		while (cha[j] != '\0')
		{
			if (cha[i] == cha[j])
			{
				return (11);
			}
			++j;
		}
		++i;
	}
	return (0);
}

void	tobase(char *base, int rule, unsigned int nownum)
{	
	unsigned int	temp;
	unsigned int	ruletemp;

	ruletemp = (unsigned int) rule;
	temp = nownum;
	if (temp >= ruletemp)
	{	
		while (temp >= ruletemp)
		{
			temp = temp % rule;
		}
		nownum = nownum / rule;
		tobase(base, rule, nownum);
		write(1, &base[temp], 1);
	}
	else
	{
		write(1, &base[nownum % rule], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	nb;
	int	nrule;
	int	dupl;

	nb = 0;
	if (base[0] == '\0' || (base[0] != '\0' && base[1] == '\0'))
		return ;
	nrule = length(base);
	if (nrule < 0)
		return ;
	dupl = duplication(base);
	if (dupl == 11)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		tobase(base, nrule, (unsigned int)-nbr);
	}
	else
	{
		tobase(base, nrule, nbr);
	}
}
