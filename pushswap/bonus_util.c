/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <minpark@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:36:19 by minpark           #+#    #+#             */
/*   Updated: 2024/11/14 16:36:34 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_pushswap.h"
#include "bonus_main_pushswap.h"

void	newtlst(t_lst *target)
{
	t_lst	*newnode;

	newnode = (t_lst *) malloc (sizeof(t_lst) * 1);
	target->back = newnode;
}

void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}
