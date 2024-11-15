/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:36:19 by minpark           #+#    #+#             */
/*   Updated: 2024/11/14 16:37:33 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_pushswap.h"
#include "bonus_main_pushswap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	while ((s1[a] != '\0' || s2[a] != '\0') && a < n)
	{
		if ((unsigned char)s1[a] > (unsigned char)s2[a])
		{
			return (1);
		}
		else if ((unsigned char)s1[a] < (unsigned char)s2[a])
		{
			return (-1);
		}
		++a;
	}
	return (0);
}

void	orderchecker(t_stack *a, t_stack *b, char *order)
{
	if ((ft_strncmp(order, "sa\n", 4) == 0))
		swap_a(a, 0);
	else if ((ft_strncmp(order, "sb\n", 4) == 0))
		swap_b(b, 0);
	else if ((ft_strncmp(order, "ss\n", 4) == 0))
		swap_s(a, b, 0);
	else if ((ft_strncmp(order, "pa\n", 4) == 0))
		push_a(a, b, 0);
	else if ((ft_strncmp(order, "pb\n", 4) == 0))
		push_b(a, b, 0);
	else if ((ft_strncmp(order, "ra\n", 4) == 0))
		rotate_a(a, 0);
	else if ((ft_strncmp(order, "rb\n", 4) == 0))
		rotate_b(b, 0);
	else if ((ft_strncmp(order, "rr\n", 4) == 0))
		rotate_r(a, b, 0);
	else if ((ft_strncmp(order, "rra\n", 5) == 0))
		reverse_rotate_a(a, 0);
	else if ((ft_strncmp(order, "rrb\n", 5) == 0))
		reverse_rotate_b(b, 0);
	else if ((ft_strncmp(order, "rrr\n", 5) == 0))
		reverse_rotate_r(a, b, 0);
	else
		error_exit();
}

void	checker_push_swap(t_stack *a, t_stack *b, t_lst *order)
{
	t_lst	*tmplst;

	tmplst = order;
	while (tmplst->value)
	{	
		orderchecker(a, b, tmplst->value);
		tmplst = tmplst->back;
	}
}

void	setbonus(int argc, char **argv, t_lst *order)
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
	checker_push_swap(stack_a, stack_b, order);
	if (check_sort(stack_a) && stack_b->head == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(parsed_argv);
	stack_free(stack_a);
	stack_free(stack_b);
}

int	main(int argc, char **argv)
{
	t_lst	*lst;
	t_lst	*templst;

	lst = (t_lst *) malloc (sizeof(t_lst) * 1);
	templst = lst;
	while (1)
	{
		templst->value = get_next_line(STDIN_FILENO);
		if (templst->value == NULL)
			break ;
		newtlst(templst);
		templst = templst->back;
	}
	setbonus(argc, argv, lst);
	return (0);
}
