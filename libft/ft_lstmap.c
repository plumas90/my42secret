/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:16:03 by minpark           #+#    #+#             */
/*   Updated: 2024/10/04 19:27:08 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*savenode;
	t_list	*newlist;
	t_list	*newnode;

	savenode = lst;
	newlist = NULL;
	while (savenode != NULL)
	{
		newnode = ft_lstnew(f(savenode->content));
		if (newnode == NULL)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newnode);
		savenode = savenode->next;
	}
	newnode = NULL;
	return (newlist);
}
