/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranchi <jfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:41:46 by jfranchi          #+#    #+#             */
/*   Updated: 2021/07/21 16:07:24 by jfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*temp;
	char		*buffer;
	static char	*save;
	ssize_t		ret;

	/*
	** Alocar memória para o array no tamanho BUFFER_SIZE + 1
	*/
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (-1);
	/*
	** Realizar leitura do arquivo texto e capturar o retorno
	*/
	ret = read(fd, buffer, BUFFER_SIZE);
	/*
	** Realizar a leitura enquanto não chegar no final do arquivo (ret <= 0)
	*/
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (save == NULL)
			save = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(save, buffer);
			free(save);
			save = temp;
		}
		if (ft_strchr(save, '\n'))
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (save);
}
