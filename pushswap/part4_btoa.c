/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part4_btoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:13:25 by minpark           #+#    #+#             */
/*   Updated: 2024/11/14 16:18:48 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_pushswap.h"

void	b_rr(t_stack *stack_b, int *position, int *top)
{
	reverse_rotate_b(stack_b, 1);
	*top = stack_b -> head -> index;
	(*position) += 1;
}

void	b_r(t_stack *stack_b, int *position, int *top)
{
	rotate_b(stack_b, 1);
	*top = stack_b -> head -> index;
	(*position) -= 1;
}

void	find_target(t_node *node, int *size, int *target)
{
	while (node != NULL)
	{
		if (node -> index == (*size) - 1)
			break ;
		(*target) += 1;
		node = node -> back;
	}
}

void	b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int		top;
	int		mid;
	int		target;
	int		size;
	t_node	*node;

	size = stack_b -> size;
	while (size > 0)
	{
		target = 0;
		node = stack_b -> head;
		top = stack_b -> head -> index;
		find_target(node, &size, &target);
		mid = size / 2;
		if (target > mid)
			while (target < size)
				b_rr(stack_b, &target, &top);
		else if (target <= mid)
			while (target > 0)
				b_r(stack_b, &target, &top);
		push_a(stack_a, stack_b, 1);
		size--;
	}
}
