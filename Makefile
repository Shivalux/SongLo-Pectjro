# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharnvon <sharnvon@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 17:25:14 by sharnvon          #+#    #+#              #
#    Updated: 2022/06/12 21:23:35 by sharnvon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
################################################################################
####  ####  ####  ####  ####  ####  ####  ####  ####  ####  ####  ####  ####  ##
##     ##    ##    ##   ##     ##    ##    ##    ##    ##    ##    ##    ##    #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
CMLX = -Lmlx -lmlx -framework OpenGl -framework AppKit

NAME = 	so_long
NAME_A = so_long.a

HEAD = so_long.h
HEAD_DIR = ./include/
HEADS = $(addprefix $(HEAD_DIR), $(addsuffix .h, $(HEAD)))

SRC = 
SRCS_DIR = ./src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .h, $(SRC)))
OBJS = $(SRC:.c=.o)

LIBFT_DIR = ./libft/
LIBFT = ./libft/libft.a
LIBPRINT_DIR = ./libftprintf/
LIBPRINT = ./libftprintf/libftprintf.a
GNL_DIR = ./getnextline/
GNL = ./getnextline/get_next_line.a
MLX_DIR = ./mlx/
MLX = ./mlx/mlx.a

NORM = norminette
FNORM_C = -R CheckFobiddenSourceHeader
FNORM_H = -R CheckDefine

RM = rm -rf

###############################################################################
###  ####  ####  ####  ####  ####  ####  ####  ####  ####  ####  ####  ####  ##
#    ##    ##    ##     ##   ##    ##     ##    ##    ##    ##    ##    ##    #

%.o : %.c
	$(CC) $(FLAGS) $(MLX) -c &< -o $@ -p ./objes/

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(LIBPRINT_DIR)
	make -C $(GNL_DIR)
	make -C $(MLX_DIR)
	ar -rc $(NAME_A) $(OBJS)
	$(CC) $(FLAGS) $(CMLX) $(NAME_A) $(LIBFT) $(LIBPRINT) $(GNL) -o $(NAME)

all : $(NAME)
.PHONY : all

norminette :
	make $(NORM) -C $(GNL_DIR)
	make $(NORM) -C $(LIBFT_DIR)
	make $(NOMR) -C $(LIBPRINT_DIR)
	$(NORM) $(FNORM_C) $(SRCS_DIR)
	$(NORM) $(FNORM_H) $(HEADS_DIR)
.PHONY : norminette

clean :
	make clean -C $(MLX_DIR)
	make clean -C $(GNL_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBPRINT_DIR)
	$(RM) $(OBJS)
.PHONY : clean

fclean : clean
	make fclean -C $(MLX_DIR)
	make fclean -C $(GNL_DIR)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(LIBPRINT_DIR)
	$(RM) $(NAME) $(NAME_A)
.PHONY : fclean

re : clean fclean all
	make re -C $(MLX_DIR)
	make re -C $(GNL_DIR)
	make re -C $(LIBFT_DIR)
	make re -C $(LIBPRINT_DIR)
.PHONY : re

 ##    ##    ##    ##    ##    ##    ##    ##    ##    ##    ##    ##    ##    #
####  ####  ####  ####  ####  ####  ####  ####  ####  ####  ####  ####  ####  ##
################################################################################
