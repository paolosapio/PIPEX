/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_docereitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:52:31 by psapio            #+#    #+#             */
/*   Updated: 2024/07/04 17:52:38 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void here_dokeitor(int *p_fds, char *limiter)
{
    crear el archivo con opeen y flag para crear.
    leer de stdin
    comprobar que lo leido no sea el limiter
    escribir con write en el archivo
}

void there_doc(int fd)
{
    close(fd);
    unlink("./tempfile")
}