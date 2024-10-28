/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:39:15 by minpark           #+#    #+#             */
/*   Updated: 2024/10/04 19:27:53 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int			count;
	t_list		*nowlist;

	nowlist = lst;
	count = 0;
	while (nowlist != NULL)
	{
		count++;
		nowlist = (*nowlist).next;
	}
	return (count);
}
