/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranchi <jfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:41:46 by jfranchi          #+#    #+#             */
/*   Updated: 2021/07/30 17:49:48 by jfranchi         ###   ########.fr       */
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
	if (save[i] == '\n')
	{
		current_line = (char *)ft_calloc(2, sizeof(char));
		current_line[i] = save[i];
	}
	else
	{
		while (save[i] && save[i] != '\n')
			i++;
		current_line = (char *)ft_calloc((i + 1), sizeof(char));
	}
	if (!current_line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		current_line[i] = save[i];
		i++;
	}
	return (current_line);
}
//carro
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
	if (ft_strcmp(next_line, ""))
	{
		free(next_line);
		return (NULL);
	}
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
	if (ret == 0 && save == NULL)
	{
		free(current_line);
		return (NULL);
	}
	printf("current_line: %s\n", current_line);
	printf("save: %s\n", save);
	return (current_line);
}
