/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:55:17 by minpark           #+#    #+#             */
/*   Updated: 2024/11/04 16:27:05 by minpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_arg
{
	int		fd[2];
	pid_t	pid;
	int		infile;
	int		outfile;
	char	**path;
	char	**cmd1;
	char	*cmd1path;
	char	**cmd2;
	char	*cmd2path;
}	t_arg;

void	close_fds(t_arg t_arg);
void	free_array(char **arr);
void	free_all(t_arg t_arg);
void	cleanup_exit(t_arg t_arg, char *message);
void	error_exit(char *message);
void	pipex(t_arg t_arg, char **envp);
char	*get_cmd(char *cmd, char **path);
char	**get_envp(char **envp);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(char const *str, char charset);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
