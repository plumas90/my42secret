/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:15:47 by minpark           #+#    #+#             */
/*   Updated: 2024/11/04 17:37:23 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

void	pipex(t_arg t_arg, char **envp)
{
	if (pipe(t_arg.fd) == -1)
		error_exit("pipe error");
	t_arg.pid = fork();
	if (t_arg.pid == -1)
		error_exit("fork error");
	if (t_arg.pid == 0)
	{
		dup2(t_arg.infile, STDIN_FILENO);
		dup2(t_arg.fd[1], STDOUT_FILENO);
		close(t_arg.fd[0]);
		close(t_arg.fd[1]);
		if (execve(t_arg.cmd1path, t_arg.cmd1, envp) == -1)
			error_exit("execve error kid command not found");
		exit(1);
	}
	dup2(t_arg.fd[0], STDIN_FILENO);
	dup2(t_arg.outfile, STDOUT_FILENO);
	close(t_arg.fd[0]);
	close(t_arg.fd[1]);
	waitpid(t_arg.pid, NULL, WNOHANG);
	if (execve(t_arg.cmd2path, t_arg.cmd2, envp) == -1)
		error_exit("execve error parent command not found");
	exit(1);
}

char	*get_cmd(char *cmd, char **path)
{
	char	*returncmd;
	char	*tmpcmd;
	int		checkfd;
	int		index;

	checkfd = access(cmd, X_OK);
	if (checkfd != -1)
		return (ft_strdup(cmd));
	tmpcmd = ft_strjoin("/", cmd);
	index = 0;
	while (path[index])
	{
		returncmd = ft_strjoin(path[index], tmpcmd);
		if (access(returncmd, X_OK) == 0)
		{
			free(tmpcmd);
			return (returncmd);
		}
		free(returncmd);
		index++;
	}
	free(tmpcmd);
	return (NULL);
}

char	**get_envp(char **envp)
{
	while (*envp)
	{
		if (!ft_strncmp("PATH", *envp, 4))
		{
			return (ft_split((*envp + 5), ':'));
		}
		envp++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	t_arg1;

	if (argc != 5)
		error_exit("value error");
	t_arg1.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	t_arg1.infile = open(argv[1], O_RDONLY);
	if (t_arg1.outfile == -1 || t_arg1.infile == -1)
		error_exit("infile or outfile open error");
	t_arg1.cmd1 = ft_split(argv[2], ' ');
	t_arg1.cmd2 = ft_split(argv[3], ' ');
	if (t_arg1.cmd1[0] == NULL || t_arg1.cmd2[0] == NULL)
		error_exit("cmd order empty");
	t_arg1.path = get_envp(envp);
	if (t_arg1.path == NULL)
		error_exit("no cmdpath");
	t_arg1.cmd1path = get_cmd(t_arg1.cmd1[0], t_arg1.path);
	t_arg1.cmd2path = get_cmd(t_arg1.cmd2[0], t_arg1.path);
	if (!t_arg1.cmd1path || !t_arg1.cmd2path)
		cleanup_exit(t_arg1, "command not found");
	if (access(t_arg1.cmd1path, X_OK) || access(t_arg1.cmd2path, X_OK))
		cleanup_exit(t_arg1, "command not found");
	pipex(t_arg1, envp);
	return (0);
}
