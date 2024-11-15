/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part4_atob.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:11:36 by minpark           #+#    #+#             */
/*   Updated: 2024/11/14 16:18:49 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_pushswap.h"

void	a_to_b_check(t_stack *stack_a, t_stack *stack_b, int *i, float chunk)
{
	int	top;

	top = stack_a -> head -> index;
	if (top <= *i)
	{
		push_b(stack_a, stack_b, 1);
		(*i)++;
	}
	else if (*i < top && top <= *i + chunk)
	{
		push_b(stack_a, stack_b, 1);
		rotate_b(stack_b, 1);
		(*i)++;
	}
	else if (*i + chunk < top)
		rotate_a(stack_a, 1);
}

void	a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int		size;
	int		i;
	float	chunk;

	size = stack_a -> size;
	i = 0;
	chunk = 0.000000053 * size * size + 0.03 * size + 14.5;
	while (i < size)
	{
		a_to_b_check(stack_a, stack_b, &i, chunk);
	}
}
