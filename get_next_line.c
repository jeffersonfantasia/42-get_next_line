/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranchi <jfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:41:46 by jfranchi          #+#    #+#             */
/*   Updated: 2021/07/30 18:44:52 by jfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*before_line_breaker(char *save)
{
	char	*current_line;
	int		i;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	current_line = (char *)ft_calloc((i + 1), sizeof(char));
	if (!current_line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		current_line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		current_line[i] = save[i];
	return (current_line);
}

char	*after_line_breaker(char *save)
{
	char	*next_line;
	int		i;
	int		j;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	next_line = (char *)ft_calloc((ft_strlen(save) - i), sizeof(char));
	if (!next_line)
		return (NULL);
	i++;
	j = 0;
	while (save[i] != '\0')
		next_line[j++] = save[i++];
	free(save);
	return (next_line);
}

char	*get_next_line(int fd)
{
	char		*current_line;
	char		*buffer;
	static char	*save;
	ssize_t		ret;

	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	ret = 1;
	while (ret != 0 && !ft_strchr(save, '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[ret] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	current_line = before_line_breaker(save);
	save = after_line_breaker(save);
	if (!save && ret == 0 && ft_strlen(current_line) == 0)
	{
		free(current_line);
		return (NULL);
	}
	return (current_line);
}
