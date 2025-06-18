/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:06:04 by jadalid-          #+#    #+#             */
/*   Updated: 2025/06/17 23:30:01 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_cmd(char *cmd, char **envp)
{
	char	**cmds;
	char	*path;

	cmds = ft_split(cmd, ' ');
	if (!cmds || !cmds[0])
	{
		free_tab(cmds);
		ft_error("commands not found");
	}
	if (ft_strchr(cmds[0], '/'))
		path = ft_strdup(cmds[0]);
	else
		path = get_path(cmds[0], envp);
	if (!path || access(path, X_OK))
	{
		free_tab(cmds);
		free(path);
		ft_putstr_fd("Command not found", 2);
		exit(127);
	}
	execve(path, cmds, envp);
	free(path);
	free_tab(cmds);
	perror("Execve failed\n");
	exit(127);
}

void	ft_first_fork(char **av, char **envp, int pipefd[2])
{
	int		fd_in;

	fd_in = open_fdin(av[1]);
	dup2(fd_in, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(fd_in);
	get_cmd(av[2], envp);
}

void	ft_second_fork(char **av, char **envp, int pipefd[2])
{
	int		fd_out;

	fd_out = open_fdout(av[4]);
	dup2(fd_out, STDOUT_FILENO);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[1]);
	close(fd_out);
	get_cmd(av[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipefd[2];
	int		status;

	if (ac != 5)
		ft_error("Argments not valid");
	if (pipe(pipefd) == -1)
		ft_error("Error make pipe");
	pid1 = fork();
	if (pid1 == -1)
		ft_error("Error make first fork");
	if (pid1 == 0)
		ft_first_fork(av, envp, pipefd);
	pid2 = fork();
	if (pid2 == -1)
		ft_error("Error make second fork");
	if (pid2 == 0)
		ft_second_fork(av, envp, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		exit (WEXITSTATUS(status));
}
