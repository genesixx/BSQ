# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/18 10:00:59 by elebouch          #+#    #+#              #
#    Updated: 2017/08/18 14:41:30 by elebouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror -O3 
EXEC = bsq

SRCS = srcs/main.c 		\
	   srcs/utility.c	\
	   srcs/libft.c		\
	   srcs/processing.c

INCLUDES = includes/

all: $(EXEC)

$(EXEC):
	$(CC) $(FLAGS) $(SRCS) -I $(INCLUDES) -o $(EXEC)

clean:

fclean: clean
	rm -f $(EXEC)

re: fclean all
