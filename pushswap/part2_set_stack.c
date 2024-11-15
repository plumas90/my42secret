/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2_set_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:39:19 by minpark           #+#    #+#             */
/*   Updated: 2024/11/13 21:09:11 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_pushswap.h"

t_stack	*set_stack(t_stack *stack)
{
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		exit (1);
	stack->size = 0;
	stack -> head = NULL;
	stack -> tail = NULL;
	return (stack);
}

void	set_allstack(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = set_stack(*stack_b);
	*stack_b = set_stack(*stack_b);
}
