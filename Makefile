# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfranchi <jfranchi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/21 19:24:43 by jfranchi          #+#    #+#              #
#    Updated: 2021/07/26 21:01:06 by jfranchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Bin
NAME = a.out

#File name
FILE = file.txt

#Compilation
CC = gcc
#FLAGS = -Wall -Werror -Wextra -fsanitize=address -D BUFFER_SIZE=2
FLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=1

#List all the source files with .c
SRCS =	get_next_line.c get_next_line_utils.c main.c

#Generate files .o for "all" rule
OBJS = $(SRCS:.c=.o)

all: $(NAME)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) && ./$(NAME) $(FILE)

$(NAME): $(OBJS)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

clean:
	@rm -vf *.out
	@rm -vf *.o

.PHONY:	all, clean