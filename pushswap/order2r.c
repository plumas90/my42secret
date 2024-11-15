/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order2r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:25:02 by minpark           #+#    #+#             */
/*   Updated: 2024/11/13 21:09:11 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_pushswap.h"

void	rotate_a(t_stack *stack_a, int type)
{
	t_node	*head;

	if (stack_a->size <= 1)
		return ;
	head = stack_a->head;
	head->front = stack_a->tail;
	stack_a->tail->back = head;
	head->back->front = NULL;
	stack_a->head = head->back;
	stack_a->tail = head;
	head->back = NULL;
	if (type)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack_b, int type)
{
	t_node	*head;

	if (stack_b->size <= 1)
		return ;
	head = stack_b->head;
	head->front = stack_b->tail;
	stack_b->tail->back = head;
	head->back->front = NULL;
	stack_b->head = head->back;
	stack_b->tail = head;
	head->back = NULL;
	if (type)
		write(1, "rb\n", 3);
}

void	rotate_r(t_stack *stack_a, t_stack *stack_b, int i)
{
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
	if (i)
		write(1, "rr\n", 3);
}
