# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wykiki <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 15:17:47 by jle-mene          #+#    #+#              #
#    Updated: 2017/02/09 10:35:03 by jle-mene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILLER_DIR = ./resources/players/
FILLER_EXT = .filler

DV_NAME = dv
DV = $(addprefix $(FILLER_DIR), $(addsuffix $(FILLER_EXT), $(DV_NAME)))

MX_NAME = many
MX = $(addprefix $(FILLER_DIR), $(addsuffix $(FILLER_EXT), $(MX_NAME)))

WYKI_NAME = jle-mene
WYKI = $(addprefix $(FILLER_DIR), $(addsuffix $(FILLER_EXT), $(WYKI_NAME)))

SRC_NAME =	\
			main\
			gnl/get_next_line\
			gui/start_gui\
			gui/loop_hook\
			gui/expose\
			gui/draw_game_rack\
			gui/draw_game_board\
			parser/start_filler\
			parser/parser\
			parser/set_piece\
			parser/play\
			parser/ft_matrixnew\
			parser/ft_matrixdel\
			ai/get_possible_positions\
			ai/piece_placing\
			ai/mid_points\
			ai/get_dist\
			ai/dv/t_coord_init

DV_SRC_NAME :=	$(SRC_NAME)\
				ai/dv/ai_dv_go_around

MX_SRC_NAME :=	$(SRC_NAME)\
				ai/many/ai_many\
				ai/many/ai_many_lst_fnct

WYKI_SRC_NAME :=	$(SRC_NAME)\
					ai/wyki/ai_wyki\
					ai/wyki/check_edge\
					ai/wyki/is_edge_occupied\
					ai/wyki/go_closer\
					ai/wyki/square_functions

EXT = .c

LIBFT_NAME =	libftprintf.a
MLXLIBFT_NAME =	mlxlibft.a

SRC_DIR =	./src/
INC_DIR =	./inc/
LIBFT_DIR =	./libft/
MLX_DIR =	./mlxlibft/
OBJ_DIR =	./obj/

CC = 		clang
FLAGS = 	-Wall -Werror -Wextra
MLX_FLAGS =	./mlxlibft/mlxlibft.a -lmlx -framework OpenGL -framework AppKit

DV_SRC =	$(addprefix $(SRC_DIR), $(addsuffix $(EXT), $(DV_SRC_NAME)))
DV_OBJ =	$(addprefix $(OBJ_DIR), $(DV_SRC:.c=.o))

MX_SRC =	$(addprefix $(SRC_DIR), $(addsuffix $(EXT), $(MX_SRC_NAME)))
MX_OBJ =	$(addprefix $(OBJ_DIR), $(MX_SRC:.c=.o))

WYKI_SRC =	$(addprefix $(SRC_DIR), $(addsuffix $(EXT), $(WYKI_SRC_NAME)))
WYKI_OBJ =	$(addprefix $(OBJ_DIR), $(WYKI_SRC:.c=.o))

LIBFT = 	$(addprefix $(LIBFT_DIR),$(LIBFT_NAME))
MLXLIBFT =	$(addprefix $(MLX_DIR),$(MLXLIBFT_NAME))

NAME_TAR = transfer.tar


all: $(DV) $(WYKI) $(MX)

dv: $(DV)

mx: $(MX)

wyki: $(WYKI)

$(DV): $(LIBFT) $(MLXLIBFT) $(DV_OBJ)
	@$(CC) $(MLX_FLAGS) $^ -o $@
	@echo "\033[92;1mDV Filler compiled\033[0m";

$(MX): $(LIBFT) $(MLXLIBFT) $(MX_OBJ)
	@$(CC) $(MLX_FLAGS) $^ -o $@
	@echo "\033[92;1mMX Filler compiled\033[0m";

$(WYKI): $(LIBFT) $(MLXLIBFT) $(WYKI_OBJ)
	@$(CC) $(MLX_FLAGS) $^ -o $@
	@cp $(WYKI) ./
	@echo "\033[92;1mWYKI Filler compiled\033[0m";

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLXLIBFT):
	@$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -o $@ -c $< -I $(INC_DIR)

clean:
	@rm -rf $(DV_OBJ)
	@rm -rf $(WYKI_OBJ)
	@rm -rf $(MANY_OBJ)
	@echo "\033[91;1mFiller objects removed\033[0m";

lclean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(DV)
	@rm -f $(WYKI)
	@rm -f $(notdir $(WYKI))
	@rm -f $(MANY)
	@echo "\033[91;1mFiller binary removed\033[0m";

aclean: fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) fclean

re: fclean all

rea: aclean all

tar: fclean
	@echo "\033[92;1mProject compressed\033[0m";
	@tar -cf $(NAME_TAR) $(SRC) Makefile $(addsuffix .h, $(NAME))
