/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:27:18 by minpark           #+#    #+#             */
/*   Updated: 2024/11/04 16:27:39 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

void	close_fds(t_arg t_arg)
{
	if (t_arg.infile > 0)
		close(t_arg.infile);
	if (t_arg.outfile > 0)
		close(t_arg.outfile);
	if (t_arg.fd[0] > 0)
		close(t_arg.fd[0]);
	if (t_arg.fd[1] > 0)
		close(t_arg.fd[1]);
}

void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_all(t_arg t_arg)
{
	if (t_arg.path)
		free_array(t_arg.path);
	if (t_arg.cmd1)
		free_array(t_arg.cmd1);
	if (t_arg.cmd2)
		free_array(t_arg.cmd2);
	if (t_arg.cmd1path)
		free(t_arg.cmd1path);
	if (t_arg.cmd2path)
		free(t_arg.cmd2path);
}

void	cleanup_exit(t_arg t_arg, char *message)
{
	close_fds(t_arg);
	free_all(t_arg);
	error_exit(message);
}

void	error_exit(char *message)
{
	perror(message);
	exit(1);
}
