/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranchi <jfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 19:09:43 by jfranchi          #+#    #+#             */
/*   Updated: 2021/07/30 17:14:30 by jfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char const *argv[])
{
	ssize_t    fd;
	char *test;
	fd = 0;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	do
	{
		test = get_next_line(fd);
		printf("|%s|\n", test);
		if (test)
			free(test);
	}
	while (test != NULL);
	if (test)
		free(test);
	close (fd);
	return (0);
}