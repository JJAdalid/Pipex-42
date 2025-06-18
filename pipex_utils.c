/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:06:09 by jadalid-          #+#    #+#             */
/*   Updated: 2025/06/17 23:19:44 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*full_path;
	char	*temp;
	int		i;

	i = 0;
	while (envp[i] && (ft_strncmp(envp[i], "PATH=", 5) != 0))
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(temp, cmd);
		free (temp);
		if (access(full_path, F_OK | X_OK) == 0)
			return (free_tab(paths), full_path);
		free(full_path);
	}
	return (free_tab(paths), NULL);
}

int	open_fdin(char *argv)
{
	int	fd_in;

	fd_in = open(argv, O_RDONLY);
	if (fd_in < 0)
	{
		perror(argv);
		exit(EXIT_FAILURE);
	}
	return (fd_in);
}

int	open_fdout(char *argv)
{
	int	fd_out;

	fd_out = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd_out < 0)
		ft_error("Error outfile");
	return (fd_out);
}
