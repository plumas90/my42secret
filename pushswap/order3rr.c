/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order3rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:25:02 by minpark           #+#    #+#             */
/*   Updated: 2024/11/13 21:09:11 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_pushswap.h"

void	reverse_rotate_a(t_stack *stack_a, int type)
{
	t_node	*tail;

	if (stack_a->size <= 1)
		return ;
	tail = stack_a->tail;
	tail->back = stack_a->head;
	stack_a->head->front = tail;
	tail->front->back = NULL;
	stack_a->head = tail;
	stack_a->tail = tail->front;
	tail->front = NULL;
	if (type)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *stack_b, int type)
{
	t_node	*tail;

	if (stack_b->size <= 1)
		return ;
	tail = stack_b->tail;
	tail->back = stack_b->head;
	stack_b->head->front = tail;
	tail->front->back = NULL;
	stack_b->head = tail;
	stack_b->tail = tail->front;
	tail->front = NULL;
	if (type)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_r(t_stack *stack_a, t_stack *stack_b, int i)
{
	reverse_rotate_a(stack_a, 0);
	reverse_rotate_b(stack_b, 0);
	if (i)
		write(1, "rrr\n", 4);
}
