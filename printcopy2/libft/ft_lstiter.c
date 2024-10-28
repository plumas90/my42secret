/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:09:50 by minpark           #+#    #+#             */
/*   Updated: 2024/10/04 19:26:19 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*nowlist;

	nowlist = lst;
	while (nowlist != NULL)
	{
		(*f)(nowlist->content);
		if (nowlist->next == NULL)
		{
			break ;
		}
		nowlist = nowlist->next;
	}
	return ;
}
