# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharnvon <sharnvon@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 17:25:14 by sharnvon          #+#    #+#              #
#    Updated: 2022/06/11 18:34:48 by sharnvon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
################################################
####  ####  ####  ####  ####  ####  ####  ####
##     ##    ##    ##   ##     ##    ##    ##

CC = gcc
FLAGS = -Wall -Werror -Wextra

NAME = 	so_long
NAME_A = so_long.a

HEAD = so_long.h
HEAD_DIR = ./include/
HEADS = $(addprefix $(HEAD_DIR), $(addsuffix .h, $(HEAD)))

LIBFT_DIR = ./libft/
LIBFT = ./libft/libft.a
LIBPRINT_DIR = ./libftprintf/
LIBPRINT = ./libftprintf/libftprintf.a
GNL_DIR = ./getnextline/
GNL = ./getnextline/get_next_line.a

NORM = norminette
FNORM_C = -R CheckFobiddenSourceHeader
FNORM_H = -R CheckDefine

SRC = 
SRCS_DIR = ./src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .h, $(SRC)))

OBJS = $(SRC:.c=.o)

################################################
###  ####  ####  ####  ####  ####  ####  ####
#    ##    ##    ##     ##   ##    ##     ##

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(LIBPRINT_DIR)
	ar -rc $(NAME_A) $(OBJS)
	$(CC) $(FLAGS) $(NAME_A) -o $(NAME)

all : $(NAME)
.PHONY : all

norminette :
	make $(NORM) -C $(GNL_DIR)
	$(NORM) $(FNORM_C) $(SRCS)
	$(NORM) $(FNORM_H) $(HEADS)
.PHONY : norminette

clean :
	rm -rf $(OBJS)
.PHONY : clean

fclean : clean
	rm -rf $(NAME) $(NAME_A)
.PHONY : fclean

re : clean fclean all
.PHONY : re

 ##    ##    ##    ##    ##    ##    ##    ##    ##
####  ####  ####  ####  ####  ####  ####  ####  ####
#####################################################
