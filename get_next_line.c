/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranchi <jfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:41:46 by jfranchi          #+#    #+#             */
/*   Updated: 2021/07/26 21:19:08 by jfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*current_line(char *save)
{
	char	*current_save;
	int		i;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	current_save = (char *)ft_calloc((i + 1), sizeof(char));
	if (current_save == NULL)
		return (NULL);
	i = -1;
	while (save[++i] && save[i] != '\n')
		current_save[i] = save[i];
	return (current_save);
}

char	*pos_new_line(char *save)
{
	char	*pos_new_save;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	pos_new_save = (char *)ft_calloc((ft_strlen(save) - i), sizeof(char));
	if (pos_new_save == NULL)
		return (NULL);
	i++;
	while (save[i])
		pos_new_save[j++] = save[i++];
	free(save);
	return (pos_new_save);
}

char	*get_next_line(int fd)
{
	char		*temp;
	char		*buffer;
	static char	*save;
	ssize_t		ret;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (buffer == NULL)
		return (NULL);
	ret = 1;
	while (ret > 0 && !ft_strchr(save, '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buffer);
			return (NULL);
		}
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	temp = current_line(save);
	save = pos_new_line(save);
	return (temp);
}
