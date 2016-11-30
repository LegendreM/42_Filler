#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/15 14:40:21 by mlegendr          #+#    #+#              #
#    Updated: 2016/11/28 17:46:55 by jle-mene         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = mlxlibft.a

SRC_NAME =	\
			new_mlx_image_8u.c\
			pixel_8u.c\
			red_8u.c\
			green_8u.c\
			blue_8u.c\
			alpha_8u.c\
			free_mlx_image_8u.c\
			new_mlx_xpm_image_8u.c\
			get_pixel_8u.c\
			create_pixel_8u.c\
			draw_square.c\
			create_roi.c\
			red_cross.c\
			clear_image_8u.c\
			draw_rack.c\
			draw_circle.c

SRC_DIR =	./src/
OBJ_DIR =	./obj/
INC_DIR =	./inc/

SRC =		$(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ =		$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC =	clang
FLAGS = -Wall -Werror -Wextra -Wconversion


all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $^
	@ranlib $(NAME)
	@echo "\033[92;1mMlxLibft compiled\033[0m";

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -o $@ -c $< -I $(INC_DIR)

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[91;1mMlxLibft objects removed\033[0m";

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[91;1mMlxLibft removed\033[0m";

re: fclean all
