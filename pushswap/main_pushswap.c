/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.qwe                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:08:08 by minpark           #+#    #+#             */
/*   Updated: 2024/11/14 15:38:48 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_pushswap.h"

int	check_sort(t_stack *stack_a)
{
	t_node	*node;
	int		check_index;

	if (!stack_a -> head)
		return (0);
	node = stack_a -> head;
	check_index = stack_a -> head -> index;
	while (node != NULL)
	{
		if (check_index != node -> index)
			return (0);
		node = node -> back;
		check_index++;
	}
	return (1);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_a -> size;
	if (size <= 3 || size == 5)
		sort_handmade(stack_a, stack_b, size);
	else
	{
		a_to_b(stack_a, stack_b);
		b_to_a(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_node	*node_a;
	int		*parsed_argv;

	stack_a = NULL;
	stack_b = NULL;
	node_a = NULL;
	parsed_argv = parsing_argv(argc, argv);
	set_allstack(&stack_a, &stack_b);
	set_node(parsed_argv, stack_a, &node_a);
	if (check_sort(stack_a))
	{
		free(parsed_argv);
		stack_free(stack_a);
		stack_free(stack_b);
		exit(0);
	}
	push_swap(stack_a, stack_b);
	free(parsed_argv);
	stack_free(stack_a);
	stack_free(stack_b);
	return (0);
}
