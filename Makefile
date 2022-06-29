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

SRCS = animating.c checkmap_misconfig.c ending_situation1.c ending_situation2.c handler_functions.c image_init1.c image_init2.c map_generated1.c \
		map_generated2.c patroling_swap.c read_map1.c read_map2.c so_long.c walking_swap.c so_long_util1.c so_long_util2.c
OBJS = $(SRCS:.c=.o)

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

all : $(OBJS)
	make -C $(LIBPRINT_DIR)
	make -C $(GNL_DIR)
	make -C $(MLX_DIR)
	ar -rc $(NAME_A) $(OBJS)
	$(CC) $(FLAGS) $(CMLX) $(NAME_A) $(LIBFT) $(LIBPRINT) $(GNL) -o $(NAME)
	@echo "\n=> MAKE COMPLETE <=\n"
.PHONY : all

bonus : all
.PHONY : bonus

norminette :
	@make $(NORM) -C $(GNL_DIR)
	@make norminette -C ./libftprintf/
	$(NORM) $(FNORM_C) $(SRCS)
	# $(NORM) $(FNORM_H) $(HEADS)
.PHONY : norminette

clean :
	make clean -C $(MLX_DIR)
	make clean -C $(GNL_DIR)
	make clean -C $(LIBPRINT_DIR)
	$(RM) $(OBJS)
.PHONY : clean

fclean : clean
	make fclean -C $(GNL_DIR)
	make fclean -C $(LIBPRINT_DIR)
	$(RM) $(NAME) $(NAME_A)
.PHONY : fclean

re : clean fclean all
	make re -C $(MLX_DIR)
	make re -C $(GNL_DIR)
	make re -C $(LIBPRINT_DIR)
.PHONY : re

 ##    ##    ##    ##    ##    ##    ##    ##    ##    ##    ##    ##    ##    #
####  ####  ####  ####  ####  ####  ####  ####  ####  ####  ####  ####  ####  ##
################################################################################
