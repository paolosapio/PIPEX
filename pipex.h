/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:08:46 by psapio            #+#    #+#             */
/*   Updated: 2024/06/11 21:58:49 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stddef.h>

char	*find_path_name(char *cmd, char **envp);
void	child_pepe_first(int *p_fds, char **argv, char **envp);
void	child_paolo_second(int *p_fds, char **argv, char **envp);

#endif
