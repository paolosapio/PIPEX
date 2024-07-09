/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:34:40 by psapio            #+#    #+#             */
/*   Updated: 2024/07/03 12:14:49 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#define WRITE 1
#define READ 0

int	openeitor(int *p_fds, const char *file, int flags, mode_t mode)
{
	int	file_fd;

	file_fd = open(file, flags, mode);
	if (file_fd == -1)
	{
		close(p_fds[WRITE]);
		close(p_fds[READ]);
		perror(file);
		exit(1);
	}
	return (file_fd);
}

void	child_pepe_first(int *p_fds, char *first_cmd, char *infile, char **envp)
{
	pid_t	family;
	int		in_fd;
	char	**cmd_arg;
	char	*path_name;

	family = fork();
	if (family == 0)
	{
		close(p_fds[READ]);
		in_fd = openeitor(p_fds, infile, O_RDONLY, 0);
		dup2(in_fd, 0);
		close(in_fd);
		cmd_arg = ft_split(first_cmd, ' ');
		path_name = find_path_name(cmd_arg[0], envp);
		dup2(p_fds[WRITE], 1);
		close(p_fds[WRITE]);
		execve(path_name, cmd_arg, NULL);
		if (cmd_arg[0] == NULL)
			cmd_arg[0] = "\"\"";
		perror(cmd_arg[0]);
		exit(1);
	}
}

void	child_pepa_midle(int *p_fds, int aux_fd_r, char *mid_cmd, char **envp)
{
	pid_t	family;
	char	**cmd_arg;
	char	*path_name;

	family = fork();
	if (family == 0)
	{
		close(p_fds[READ]);
		dup2(aux_fd_r, 0);
		close(aux_fd_r);
		cmd_arg = ft_split(mid_cmd, ' ');
		path_name = find_path_name(cmd_arg[0], envp);
		dup2(p_fds[WRITE], 1);
		close(p_fds[WRITE]);
		execve(path_name, cmd_arg, envp);
		if (cmd_arg[0] == NULL)
			cmd_arg[0] = "\"\"";
		perror(cmd_arg[0]);
		exit(1);
	}
	close(p_fds[WRITE]);
	close(aux_fd_r);
}

pid_t	child_paolo_last(int *p_fds, char *last_cmd, char *outfile, char **envp)
{
	pid_t	family;
	int		out_fd;
	char	**cmd_arg;
	char	*path_name;

	family = fork();
	if (family == 0)
	{
		close(p_fds[WRITE]);
		out_fd = openeitor(p_fds, outfile, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		dup2(out_fd, 1);
		close(out_fd);
		cmd_arg = ft_split(last_cmd, ' ');
		path_name = find_path_name(cmd_arg[0], envp);
		dup2(p_fds[READ], 0);
		close(p_fds[READ]);
		execve(path_name, cmd_arg, envp);
		if (cmd_arg[0] == NULL)
			cmd_arg[0] = "\"\"";
		perror(cmd_arg[0]);
		exit(1);
	}
	return (family);
}
