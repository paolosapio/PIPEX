/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:04:12 by psapio            #+#    #+#             */
/*   Updated: 2024/07/01 18:57:14 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#define WRITE 1
#define READ 0

int	main(int argc, char **argv, char **envp)
{
	int		p_fds[2];
	int		status;
	pid_t	last;

	if (argc < 5)
	{
		print_error("Usage: ./pipex file1 cmd1 cmd2 file2\n");
		exit(EXIT_FAILURE);
	}
	pipe(p_fds);
	child_pepe_first(p_fds, argv, envp);
	last = child_paolo_second(p_fds, argv, envp);
	close(p_fds[WRITE]);
	close(p_fds[READ]);
	waitpid(last, &status, 0);
	waitpid(-1, NULL, 0);
	return ((char)(status >> 8));
}