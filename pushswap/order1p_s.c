/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order1p_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:25:02 by minpark           #+#    #+#             */
/*   Updated: 2024/11/13 21:09:11 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_pushswap.h"

void	push_a(t_stack *stack_a, t_stack *stack_b, int i)
{
	t_node	*node_tmp;

	if (stack_b -> head == NULL)
		return ;
	node_tmp = stack_b -> head;
	if (node_tmp -> back)
	{
		node_tmp -> back -> front = NULL;
		stack_b -> head = node_tmp -> back;
	}
	else
	{
		stack_b -> head = NULL;
		stack_b -> tail = NULL;
	}
	node_tmp -> back = stack_a -> head;
	if (stack_a -> head)
		stack_a -> head -> front = node_tmp;
	stack_a -> head = node_tmp;
	if (!stack_a -> tail)
		stack_a -> tail = node_tmp;
	ft_reset_lstsize(stack_a, stack_b);
	if (i)
		write(1, "pa\n", 3);
}

void	push_b(t_stack *stack_a, t_stack *stack_b, int i)
{
	t_node	*node_tmp;

	if (stack_a -> head == NULL)
		return ;
	node_tmp = stack_a -> head;
	if (node_tmp -> back)
	{
		node_tmp -> back -> front = NULL;
		stack_a -> head = node_tmp -> back;
	}
	else
	{
		stack_a -> head = NULL;
		stack_a -> tail = NULL;
	}
	node_tmp -> back = stack_b -> head;
	if (stack_b -> head)
		stack_b -> head -> front = node_tmp;
	stack_b -> head = node_tmp;
	if (!stack_b -> tail)
		stack_b -> tail = node_tmp;
	ft_reset_lstsize(stack_a, stack_b);
	if (i)
		write(1, "pb\n", 3);
}

void	swap_a(t_stack *stack_a, int check)
{
	t_node	*temp_node;
	t_node	*temp_next_node;

	if (stack_a == NULL)
		return ;
	if (stack_a->size <= 1)
		return ;
	temp_node = stack_a->head;
	temp_next_node = temp_node->back;
	temp_node->back = temp_next_node->back;
	temp_node->front = temp_next_node;
	temp_next_node->back = temp_node;
	temp_next_node->front = NULL;
	stack_a->head = temp_next_node;
	if (check == 1)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack_b, int check)
{
	t_node	*temp_node2;
	t_node	*temp_next_node2;

	if (stack_b == NULL)
		return ;
	if (stack_b->size <= 1)
		return ;
	temp_node2 = stack_b->head;
	temp_next_node2 = temp_node2->back;
	temp_node2->back = temp_next_node2->back;
	temp_node2->front = temp_next_node2;
	temp_next_node2->back = temp_node2;
	temp_next_node2->front = NULL;
	stack_b->head = temp_next_node2;
	if (check == 1)
		write(1, "sb\n", 3);
}

void	swap_s(t_stack *stack_a, t_stack *stack_b, int i)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	if (i)
		write(1, "ss\n", 3);
}
