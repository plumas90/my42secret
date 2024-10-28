/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:58:59 by minpark           #+#    #+#             */
/*   Updated: 2024/10/05 16:25:38 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nowlist;
	t_list	*nextlist;

	nowlist = *lst;
	while (nowlist != NULL)
	{
		nextlist = nowlist->next;
		del(nowlist->content);
		free(nowlist);
		nowlist = nextlist;
	}
	*lst = NULL;
	return ;
}
