#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

char *ft_strjoin(const char *s1, const char *s2);
char	**ft_split(char const *str, char charset);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

typedef struct s_arg
{
	int fd[2];
	pid_t pid;
	int infile;
	int outfile;
	char **path;
	char **cmd1;
	char *cmd1path;
	char **cmd2;
	char *cmd2path;
} t_arg;

void	error_exit(char *message)
{
	perror(message);
	exit(1);
}
void pipex(t_arg t_arg, char **envp)
{
	if (pipe(t_arg.fd) == -1)
		error_exit("pipe error");
	if ((t_arg.pid = fork()) == -1)
		error_exit("fail pid fork");
	if (t_arg.pid != 0) // 부모
	{
		close(t_arg.fd[1]);
		dup2(t_arg.fd[0],STDIN_FILENO);
		dup2(t_arg.outfile,STDOUT_FILENO);
		close(t_arg.fd[0]);
		close(t_arg.outfile);
		waitpid(t_arg.pid, NULL, 0);
		execve(t_arg.cmd2path, &t_arg.cmd2[0], envp);
	}
	else //자식
	{
		close(t_arg.fd[0]);
		dup2(t_arg.infile, STDIN_FILENO);
		dup2(t_arg.fd[1], STDOUT_FILENO);
		close(t_arg.fd[1]);
		close(t_arg.infile);
		execve(t_arg.cmd1path, &t_arg.cmd1[0],envp);
	}
}
char *get_cmd(char *cmd, char **path)
{
	char *returncmd;
	char *tmpcmd;
	int checkfd;
	int index;

	checkfd = access(cmd, X_OK);
	if (checkfd != -1)
		return (cmd);
	tmpcmd = ft_strjoin("/", cmd);
	index = 0;
	while (path[index])
	{
		returncmd = ft_strjoin(path[index],tmpcmd);
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
char **get_envp(char **envp)
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
int main(int argc, char **argv, char **envp)
{
	int check_fd;
	t_arg t_arg1;

	if (argc != 5)
		error_exit("value error");
	if (access(argv[0],R_OK) == -1 || (check_fd= open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0777) == -1))
		error_exit("infile open error OR outfile open error");
	t_arg1.infile = open(argv[1],O_RDONLY);
	t_arg1.cmd1 = ft_split(argv[2], ' ');
	t_arg1.cmd2 = ft_split(argv[3], ' ');
	if (t_arg1.cmd1 == NULL || t_arg1.cmd2 == NULL)
		error_exit("cmd order empty");
	t_arg1.outfile = check_fd;
	t_arg1.path = get_envp(envp);

	if(t_arg1.path == NULL)
		error_exit("no cmdpath");
	t_arg1.cmd1path = get_cmd(t_arg1.cmd1[0],t_arg1.path);
	t_arg1.cmd2path = get_cmd(t_arg1.cmd2[0],t_arg1.path);
	if(t_arg1.cmd1[0] == NULL ||t_arg1.cmd2[0] == NULL)
		error_exit("cant find cmd order");
	pipex(t_arg1,envp);
	return (0);
}
