/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:04:12 by psapio            #+#    #+#             */
/*   Updated: 2024/07/04 17:07:16 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#define WRITE 1
#define READ 0

void	wait_all(pid_t last_family)
{
	pid_t	ret_wait;
	int		status;
	int		final_status;

	while (1)
	{
		ret_wait = waitpid(-1, &status, 0);
		if (ret_wait == -1)
			break ;
		if (ret_wait == last_family)
			final_status = status >> 8;
	}
	exit((unsigned char)final_status);
}

void	final_return(int argc, char **argv, char **envp, int *p_fds)
{
	pid_t	last_family;

	last_family = child_paolo_last(p_fds, argv[argc - 2], argv[argc - 1], envp);
	close(p_fds[WRITE]);
	close(p_fds[READ]);
	unlink("/tmp/tempfile");
	wait_all(last_family);
}

int	parser(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5)
		print_error("Usage: ./pipex file1 cmd1 cmd2 file2\n");
	if (argc > 5 && ft_strcmp(argv[1], "here_doc") == 0)
	{
		i = 1;
		argv[2] = here_dokeitor(argv[2]);
	}
	return (i);
}

int	main(int argc, char **argv, char **envp)
{
	int		p_fds[2];
	int		i;
	int		aux_fd_r;

	i = parser(argc, argv);
	if (pipe(p_fds) == -1)
		return (1);
	child_pepe_first(p_fds, argv[2 + i], argv[1 + i], envp);
	if (argc > 5)
	{
		i = 3 + i;
		while (i < (argc - 2))
		{
			aux_fd_r = p_fds[READ];
			close(p_fds[WRITE]);
			if (pipe(p_fds) == -1)
				exit(1);
			child_pepa_midle(p_fds, aux_fd_r, argv[i], envp);
			i++;
		}
	}
	final_return(argc, argv, envp, p_fds);
}
