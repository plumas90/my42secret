/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:49:30 by minpark           #+#    #+#             */
/*   Updated: 2024/10/04 19:26:42 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp_lst;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	else
	{
		temp_lst = ft_lstlast(*lst);
		temp_lst->next = new;
	}
}
