/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranchi <jfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:41:46 by jfranchi          #+#    #+#             */
/*   Updated: 2021/07/30 14:19:03 by jfranchi         ###   ########.fr       */
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
	while (save && save[i] != '\n')
		i++;
	current_line = (char *)ft_calloc((i + 1), sizeof(char));
	if (!current_line)
		return (NULL);
	i = 0;
	while (save && save[i] != '\n')
	{
		current_line[i] = save[i];
		i++;
	}
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
	while (save && save[i] != '\n')
		i++;
	i++;
	while (save[i + j] != '\0')
		j++;
	next_line = (char *)ft_calloc((j + 1), sizeof(char));
	if (!next_line)
		return (NULL);
	j = 0;
	while (save[i] != '\0')
	{
		next_line[j] = save[i];
		j++;
		i++;
	}
	free(save);
	return (next_line);
}

char	*get_next_line(int fd)
{
	char		*current_line;
	char		*next_line;
	char		*buffer;
	static char	*save;
	ssize_t		ret;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
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
		buffer[ret] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	current_line = before_line_breaker(save);
	next_line = after_line_breaker(save);
	save = next_line;
	puts("------------------------------------------");
	printf("current_line: %s\n", current_line);
	printf("next_line: %s\n", next_line);
	printf("save: %s\n", save);
	puts("------------------------------------------");
	return (current_line);
}
