/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part4_handmade.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:06:40 by minpark           #+#    #+#             */
/*   Updated: 2024/11/14 16:38:12 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_pushswap.h"

void	sort_size_three(t_stack *stack_a)
{
	while (stack_a -> tail -> index != 2)
		rotate_a(stack_a, 1);
	if (check_sort(stack_a))
		return ;
	else
		swap_a(stack_a, 1);
}

void	sort_size_five(t_stack *stack_a, t_stack *stack_b, int *zero_idx)
{
	if (*zero_idx > 2)
		while (stack_a -> head -> index != 0)
			reverse_rotate_a(stack_a, 1);
	else if (*zero_idx <= 2)
		while (stack_a -> head -> index != 0)
			rotate_a(stack_a, 1);
	push_b(stack_a, stack_b, 1);
	while (stack_a -> head -> index != 1)
		rotate_a(stack_a, 1);
	push_b(stack_a, stack_b, 1);
	while (stack_a -> tail -> index != 4)
		rotate_a(stack_a, 1);
	if (!check_sort(stack_a))
		swap_a(stack_a, 1);
	push_a(stack_a, stack_b, 1);
	push_a(stack_a, stack_b, 1);
}

void	sort_handmade(t_stack *stack_a, t_stack *stack_b, int size)
{
	int		zero_idx;
	t_node	*node;

	node = stack_a -> head;
	zero_idx = 0;
	if (size == 2)
		rotate_a(stack_a, 1);
	else if (size == 3)
		sort_size_three(stack_a);
	else if (size == 5)
	{
		while (!(node -> index == 0))
		{
			zero_idx++;
			node = node -> back;
		}
		sort_size_five(stack_a, stack_b, &zero_idx);
	}
}
