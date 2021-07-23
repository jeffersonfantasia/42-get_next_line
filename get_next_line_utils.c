/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranchi <jfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:41:43 by jfranchi          #+#    #+#             */
/*   Updated: 2021/07/23 16:33:30 by jfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*str_m;
	int		i;

	len = ft_strlen(str) ;
	str_m = (char *)malloc((len + 1) * sizeof(char));
	if (str_m == NULL)
		return (NULL);
	str_m[len] = '\0';
	i = -1;
	while (str[++i])
		str_m[i] = str[i];
	return (str_m);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	if (c == 0)
	{
		i = 0;
		while (str[i])
			i++;
		return ((char *)str + i);
	}
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = 0;
	i = -1;
	while (*(s1 + ++i) != '\0')
		*(str + i) = *(s1 + i);
	j = 0;
	while (*(s2 + j) != '\0')
		*(str + i++) = *(s2 + j++);
	*(str + i) = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
