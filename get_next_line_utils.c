/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranchi <jfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:41:43 by jfranchi          #+#    #+#             */
/*   Updated: 2021/07/26 21:25:56 by jfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

void	*ft_calloc(size_t num, size_t len)
{
	void	*p_src;
	size_t	i;

	p_src = (void *)malloc(num * len);
	if (p_src == NULL)
		return (NULL);
	i = 0;
	while (i < (num * len))
	{
		((unsigned char *)p_src)[i] = '\0';
		i++;
	}
	return (p_src);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*str_m;
	int		i;

	len = ft_strlen(str) ;
	str_m = (char *)ft_calloc((len + 1), sizeof(char));
	if (str_m == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		str_m[i] = str[i];
	return (str_m);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	if (!str)
		return (NULL);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1 && (*(s1 + i)) )
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (s2 && (*(s2 + j)))
	{
		*(str + i) = *(s2 + j);
		i++;
		j++;
	}
	free(s1);
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}
