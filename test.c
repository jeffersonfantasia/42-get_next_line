/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranchi <jfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:18:46 by jfranchi          #+#    #+#             */
/*   Updated: 2021/07/26 14:39:33 by jfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char const **argv)
{
	ssize_t	fd;
	int		i;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	i = 0;
	while (i++ < 6)
	{
		printf("%s\n", get_next_line(fd));
	}
	close (fd);

}