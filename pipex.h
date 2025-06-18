/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:06:02 by jadalid-          #+#    #+#             */
/*   Updated: 2025/06/17 22:09:42 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# include "./libft/libft.h"

void	ft_error(char *msg);
void	ft_first_fork(char **av, char **envp, int pipefd[2]);
void	ft_second_fork(char **av, char **envp, int pipefd[2]);
void	get_cmd(char *cmd, char **envp);
char	*get_path(char *cmd, char **envp);
int		open_fdin(char *argv);
int		open_fdout(char *argv);

#endif