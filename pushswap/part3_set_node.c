/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part3_set_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:59:49 by minpark           #+#    #+#             */
/*   Updated: 2024/11/13 21:09:11 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_pushswap.h"

void	make_index(t_node *node_a)
{
	int		count;
	t_node	*temp_node;
	t_node	*first_node_a;

	temp_node = node_a;
	first_node_a = node_a;
	while (node_a)
	{
		count = 0;
		while (temp_node)
		{
			if (node_a->value > temp_node->value)
				count++;
			temp_node = temp_node->back;
		}
		node_a -> index = count;
		node_a = node_a -> back;
		temp_node = first_node_a;
	}
	node_a = 0;
}

void	make_list(int *data, t_stack *stack_a, t_node **node_a)
{
	int	i;

	i = 1;
	while (i <= data[0])
	{
		ft_lstadd_back(node_a, ft_lstnew(data[i]));
		i++;
	}
	stack_a->head = *node_a;
	stack_a->tail = ft_lstlast(*node_a);
	stack_a->size = ft_lstsize(*node_a);
}

void	set_node(int *argv, t_stack *stack_a, t_node **node_a)
{
	make_list(argv, stack_a, node_a);
	make_index(*node_a);
}
