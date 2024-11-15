/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:05:53 by minpark           #+#    #+#             */
/*   Updated: 2024/11/14 16:00:55 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_PUSHSWAP_H
# define MAIN_PUSHSWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	char			*str;
	int				value;
	int				index;
	struct s_node	*front;
	struct s_node	*back;
}					t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*head;
	struct s_node	*tail;
}					t_stack;

t_stack		*set_stack(t_stack *stack);
t_node		*ft_lstnew(int value);
t_node		*ft_lstlast(t_node *lst);
size_t		ft_strlen(const char *str);
int			ft_lstsize(t_node *lst);
int			check_sort(t_stack *stack_a);
long long	ft_atoi(const char *str);
int			check_spaces(char **argv);
int			check_null(char **argv);
int			check_digit(char **argv);
int			check_sign(char **argv);
int			*parsing_argv(int argc, char **argv);
int			check_size(char **av, int i, int end_index);
int			try_malloc(char **result, int *wd, int *wd_idx, int *wd_start);
int			c_w(char const *str, char *charset);
int			str_c(char *a, char me);
int			check_int_range(long long number);
void		ft_lstadd_back(t_node **lst, t_node *newlst);
void		ft_reset_lstsize(t_stack *stack_a, t_stack *stack_b);
void		push_swap(t_stack *stack_a, t_stack *stack_b);
void		swap_s(t_stack *stack_a, t_stack *stack_b, int check);
void		swap_b(t_stack *stack_b, int check);
void		swap_a(t_stack *stack_a, int check);
void		push_b(t_stack *stack_a, t_stack *stack_b, int i);
void		push_a(t_stack *stack_a, t_stack *stack_b, int i);
void		rotate_r(t_stack *stack_a, t_stack *stack_b, int check);
void		rotate_b(t_stack *stack_b, int type);
void		rotate_a(t_stack *stack_a, int type);
void		reverse_rotate_a(t_stack *stack_a, int type);
void		reverse_rotate_b(t_stack *stack_b, int type);
void		reverse_rotate_r(t_stack *stack_a, t_stack *stack_b, int check);
void		check_argv(char **argv);
void		duplicate_check(int *result);
void		atoi_array(int *result, char **temp, int size);
void		set_allstack(t_stack **stack_a, t_stack **stack_b);
void		make_index(t_node *node_a);
void		make_list(int *argv, t_stack *stack_a, t_node **node_a);
void		set_node(int *argv, t_stack *stack_a, t_node **node_a);
void		a_to_b_check(t_stack *stack_a, t_stack *stack_b, \
			int *i, float chunk);
void		a_to_b(t_stack *stack_a, t_stack *stack_b);
void		b_rr(t_stack *stack_b, int *position, int *top);
void		b_r(t_stack *stack_b, int *position, int *top);
void		find_target(t_node *node, int *size, int *target);
void		b_to_a(t_stack *stack_a, t_stack *stack_b);
void		sort_size_three(t_stack *stack_a);
void		sort_size_five(t_stack *stack_a, t_stack *stack_b, int *zero_idx);
void		sort_handmade(t_stack *stack_a, t_stack *stack_b, int size);
void		make_result(char *word, char *av, int index, int length);
void		make_result_from_av(char **result, char **av);
void		sort_size_three(t_stack *stack_a);
void		sort_size_five(t_stack *stack_a, t_stack *stack_b, int *zero_idx);
void		sort_handmade(t_stack *stack_a, t_stack *stack_b, int size);
void		stack_free(t_stack *stack_a);
char		**ft_split(char *str, char *char_t);
char		**ft_split2(int argc, char **argv, int i);
char		**ft_freeall(char **list);
#endif