# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfranchi <jfranchi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/21 19:24:43 by jfranchi          #+#    #+#              #
#    Updated: 2021/07/30 14:26:45 by jfranchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Bin
NAME = a.out

#File name
FILE = file.txt

#Compilation
CC = gcc
#FLAGS = -Wall -Werror -Wextra -fsanitize=address -D BUFFER_SIZE=2
FLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=7

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

git:
	git add .
	git commit -m "create or upload files"
	git push origin

.PHONY:	all, clean