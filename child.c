/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:34:40 by psapio            #+#    #+#             */
/*   Updated: 2024/07/01 19:01:55 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#define WRITE 1
#define READ 0

int	openeitor(const char *file, int flags, mode_t mode)
{
	int	file_fd;

	file_fd = open(file, flags, mode);
	if (file_fd == -1)
	{
		perror(file);
		exit(42);
	}
	return (file_fd);
}

void	child_pepe_first(int *p_fds, char **argv, char **envp)
{
	pid_t	family;
	int		in_fd;
	char	**cmd_arg;
	char	*path_name;

	family = fork();
	if (family == 0)
	{
		close(p_fds[READ]);
		in_fd = openeitor(argv[1], O_RDONLY, 0);
		dup2(in_fd, 0);
		close(in_fd);
		cmd_arg = ft_split(argv[2], ' ');
		path_name = find_path_name(cmd_arg[0], envp);
		dup2(p_fds[WRITE], 1);
		close(p_fds[WRITE]);
		execve(path_name, cmd_arg, envp);
		if (cmd_arg[0] == NULL)
			cmd_arg[0] = "\"\"";
		perror(cmd_arg[0]);
		exit(42);
	}
}

pid_t	child_paolo_second(int *p_fds, char **argv, char **envp)
{
	pid_t	family;
	int		out_fd;
	char	**cmd_arg;
	char	*path_name;

	family = fork();
	if (family == 0)
	{
		close(p_fds[WRITE]);
		out_fd = openeitor(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
		dup2(out_fd, 1);
		close(out_fd);
		cmd_arg = ft_split(argv[3], ' ');
		path_name = find_path_name(cmd_arg[0], envp);
		dup2(p_fds[READ], 0);
		close(p_fds[READ]);
		execve(path_name, cmd_arg, envp);
		if (cmd_arg[0] == NULL)
			cmd_arg[0] = "\"\"";
		perror(cmd_arg[0]);
		exit(42);
	}
	return (family);
}
