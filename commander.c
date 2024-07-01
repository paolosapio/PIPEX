/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commander.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:13:14 by psapio            #+#    #+#             */
/*   Updated: 2024/07/01 21:13:23 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#define WRITE 1
#define READ 0

void	print_error(const char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
}

char	*check_path(char **all_path, char *cmd)
{
	char	*path_name;
	int		i;
	char	*aux_free;

	i = 0;
	while (all_path[i])
	{
		path_name = ft_strjoin(all_path[i], "/");
		aux_free = path_name;
		path_name = ft_strjoin(path_name, cmd);
		free(aux_free);
		if (access(path_name, X_OK) == -1)
		{
			i++;
			free(path_name);
		}
		else
			return (path_name);
	}
	return (NULL);
}

char	*find_path_name(char *cmd, char **envp)
{
	char	**all_path;
	char	*path_name;
	int		i;

	if (cmd == NULL || ft_strchr(cmd, '/') != NULL)
		return (cmd);
	i = 0;
	while (envp[i++] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			all_path = ft_split(envp[i] + 5, ':');
			break ;
		}
	}
	i = 0;
	path_name = check_path(all_path, cmd);
	free_double_pointer(all_path);
	if (path_name == NULL)
	{
		write(2, cmd, ft_strlen(cmd));
		write(2, ": command not found\n", 21);
		exit(42);
	}
	return (path_name);
}