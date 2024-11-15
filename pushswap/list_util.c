/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:24:42 by minpark           #+#    #+#             */
/*   Updated: 2024/11/13 21:09:11 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_pushswap.h"

t_node	*ft_lstnew(int value)
{
	t_node	*new_lst;

	new_lst = (t_node *)malloc(sizeof(t_node));
	if (new_lst == NULL)
		exit (1);
	new_lst->value = value;
	new_lst -> index = 0;
	new_lst -> back = NULL;
	new_lst -> front = NULL;
	return (new_lst);
}

t_node	*ft_lstlast(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while ((lst->back) != NULL)
		lst = lst->back;
	return (lst);
}

void	ft_lstadd_back(t_node **lst, t_node *newlst)
{
	t_node	*templst;

	if (newlst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = newlst;
		return ;
	}
	else
	{
		templst = *lst;
		while (templst -> back)
		{
			templst -> back -> front = templst;
			templst = templst -> back;
		}
		templst -> back = newlst;
		newlst -> front = templst;
		newlst -> back = NULL;
	}
}

int	ft_lstsize(t_node *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		lst = lst->back;
		i++;
	}
	return (i);
}

void	ft_reset_lstsize(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = ft_lstsize(stack_a->head);
	stack_b->size = ft_lstsize(stack_b->head);
}
