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

void	child_pepa_midle(int *p_fds, int aux_pfd_read, char *argv, char **envp);

int	main(int argc, char **argv, char **envp)
{
	int		p_fds[2];
	int		i;
	int		aux_pfd_read;

	if (argc < 5)
	{
		print_error("Usage: ./pipex file1 cmd1 cmd2 file2\n");
		exit(EXIT_FAILURE);
	}
	pipe(p_fds);
	child_pepe_first(p_fds, argv, envp);
	if (argc > 5)
	{
		i = 3; // es el argumneto de inicio de la pepa
		while (i < (argc - 2))
		{
			aux_pfd_read = p_fds[READ];
			close(p_fds[WRITE]);
			pipe(p_fds);
			child_pepa_midle(p_fds, aux_pfd_read, argv[i], envp);
			i++;
		}
	}
	close(aux_pfd_read);
	child_paolo_last(p_fds, argv[argc - 2], argv[argc - 1], envp);
	close(p_fds[WRITE]);
	close(p_fds[READ]);
	while(1)
	{
		if (waitpid(-1, NULL, 0) == -1)
			break ;
	}
	return (0);
}
