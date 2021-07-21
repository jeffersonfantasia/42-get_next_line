/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranchi <jfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:41:43 by jfranchi          #+#    #+#             */
/*   Updated: 2021/07/20 21:00:14 by jfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*str_m;

	len = ft_strlen(str) + 1;
	str_m = (char *)malloc(len * sizeof(char));
	if (str_m == NULL)
		return (NULL);
	ft_memcpy(str_m, str, len);
	return (str_m);
}

void	*ft_memcpy(void *p_dest, const void *p_src, size_t len)
{
	unsigned char	*src;
	unsigned char	*dest;

	src = (unsigned char *)p_src;
	dest = (unsigned char *)p_dest;
	if (p_dest == NULL && p_src == NULL)
		return (NULL);
	while (len--)
	{
		*(dest) = *(src);
		dest++;
		src++;
	}
	return (p_dest);
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
