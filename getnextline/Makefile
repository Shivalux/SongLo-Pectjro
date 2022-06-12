# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharnvon <sharnvon@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 18:11:37 by sharnvon          #+#    #+#              #
#    Updated: 2022/06/11 18:28:30 by sharnvon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = get_next_line.a
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
HEAD = get_next_line.h


all : $(OBJS)
	$(CC) $(FLAGS) -c $(SRCS)
	ar -rc get_next_line.a $(OBJS)
.PHONY : all

norminette :
	norminette -R CheckForbiddenSourceHeader $(SRCS)
	norminette -R CheckDefine $(HEAD)

clean :
	rm -rf $(OBJS)
.PHONY : clean

fclean : clean
	rm -rf $(NAME)
.PHONY : fclean

re : clean fclean all
.PHONY : re


