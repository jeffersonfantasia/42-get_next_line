/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranchi <jfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:41:49 by jfranchi          #+#    #+#             */
/*   Updated: 2021/07/29 21:46:55 by jfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>

ssize_t	BUFFER_SIZE = 1;

char	*ft_strjoin(char *s1, char *s2);
char	*verify_line_breaker(char *str);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t num, size_t len);
char	*get_next_line(int fd);

#endif