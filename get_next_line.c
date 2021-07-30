/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranchi <jfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:41:46 by jfranchi          #+#    #+#             */
/*   Updated: 2021/07/29 21:47:21 by jfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*current_line(char *save)
{
	char	*before_line_breaker;
	int		i;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	before_line_breaker = (char *)ft_calloc((i + 1), sizeof(char));
	if (before_line_breaker == NULL)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		before_line_breaker[i] = save[i];
		i++;
	}
	return (before_line_breaker);
}

char	*next_line(char *save)
{
	char	*after_line_breaker;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	after_line_breaker = (char *)ft_calloc((ft_strlen(save) - i), sizeof(char));
	if (after_line_breaker == NULL)
		return (NULL);
	i++;
	while (save[i])
	{
		after_line_breaker[j] = save[i];
		j++;
		i++;
	}
	free(save);
	return (after_line_breaker);
}

char	*get_next_line(int fd)
{
	char		*before_line_breaker;
	char		*buffer;
	static char	*save;
	ssize_t		ret;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	ret = 1;
	while (ret > 0 && !verify_line_breaker(save))
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
	before_line_breaker = current_line(save);
	save = next_line(save) ;
	return (before_line_breaker);
}
