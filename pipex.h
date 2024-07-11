/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:08:46 by psapio            #+#    #+#             */
/*   Updated: 2024/07/08 11:46:53 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include "GNL/get_next_line_bonus.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stddef.h>

char	*find_path_name(char *cmd, char **envp, char **cmd_arg);
void	child_pepe_first(int *p_fds, char *first_cmd, char *in_f, char **envp);
void	child_pepa_midle(int *p_fds, int aux_fd_r, char *argv, char **envp);
pid_t	child_paolo_last(int *p_fds, char *last_cmd, char *out_f, char **envp);
void	print_error(const char *msg);
char	*here_dokeitor(char *limiter);

#endif
