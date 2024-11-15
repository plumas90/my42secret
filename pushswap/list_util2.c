/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:24:42 by minpark           #+#    #+#             */
/*   Updated: 2024/11/13 21:09:11 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_pushswap.h"

void	stack_free(t_stack *stack_a)
{
	t_node	*tmp_node;
	t_node	*next_node;

	if (!stack_a->head)
		return (free(stack_a));
	tmp_node = stack_a->head;
	while (tmp_node)
	{
		next_node = tmp_node->back;
		free(tmp_node);
		tmp_node = next_node;
	}
	return (free(stack_a));
}
