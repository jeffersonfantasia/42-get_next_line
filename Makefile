# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfranchi <jfranchi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/21 19:24:43 by jfranchi          #+#    #+#              #
#    Updated: 2021/07/26 14:38:06 by jfranchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Bin
NAME = a.out

#File name
FILE = file.txt

#Compilation
CC = gcc
FLAGS = -Wall -Werror -Wextra -fsanitize=address -D BUFFER_SIZE=2
#FLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=4

#List all the source files with .c
SRCS =	get_next_line.c get_next_line_utils.c main.c

all:
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) && ./$(NAME) $(FILE)

clean:
	@rm -vf *.out

t:
	$(CC) $(FLAGS) get_next_line.c get_next_line_utils.c test.c -o test.out && ./test.out $(FILE)

.PHONY:	all, clean, t