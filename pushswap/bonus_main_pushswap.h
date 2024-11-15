/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main_pushswap.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:05:53 by minpark           #+#    #+#             */
/*   Updated: 2024/11/14 16:30:28 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_MAIN_PUSHSWAP_H
# define BONUS_MAIN_PUSHSWAP_H
# include "main_pushswap.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_lst
{
	char			*value;
	struct s_lst	*back;
}					t_lst;

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
int		ft_strchr2(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_more_read(char **backup);
int		ft_read_file(int fd, char *buffer, char **backup);
char	*get_line(int fd, char *buffer, char **backup);
char	*get_next_line(int fd);
void	orderchecker(t_stack *a, t_stack *b, char *order);
void	checker_push_swap(t_stack *a, t_stack *b, t_lst *newlst);
void	newtlst(t_lst *target);
void	setbonus(int argc, char **argv, t_lst *order);
void	error_exit(void);

#endif