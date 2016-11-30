# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wykiki <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 15:17:47 by jle-mene          #+#    #+#              #
#    Updated: 2016/11/30 10:02:59 by jle-mene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

SRC_NAME =	\
			main\
			gnl/get_next_line\
			loop_hook\
			expose\
			draw_game_rack
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

SRC =		$(addprefix $(SRC_DIR), $(addsuffix $(EXT), $(SRC_NAME)))
OBJ =		$(addprefix $(OBJ_DIR), $(SRC:.c=.o))
LIBFT = 	$(addprefix $(LIBFT_DIR),$(LIBFT_NAME))
MLXLIBFT =	$(addprefix $(MLX_DIR),$(MLXLIBFT_NAME))

NAME_TAR = transfer.tar


all: $(NAME)

$(NAME): $(LIBFT) $(MLXLIBFT) $(OBJ)
	@$(CC) $(MLX_FLAGS) $^ -o $@
	@echo "\033[92;1mFiller compiled\033[0m";

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "\033[92;1mLibftprintf compiled\033[0m";

$(MLXLIBFT):
	@$(MAKE) -C $(MLX_DIR)
	@echo "\033[92;1mMlxLibft compiled\033[0m";

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -o $@ -c $< -I $(INC_DIR)

clean:
	@rm -rf $(OBJ)
	@echo "\033[91;1mFiller objects removed\033[0m";

lclean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@echo "\033[91;1mFiller binary removed\033[0m";

aclean: fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) fclean

re: fclean all

rea: aclean all

tar: fclean
	@echo "\033[92;1mProject compressed\033[0m";
	@tar -cf $(NAME_TAR) $(SRC) Makefile $(addsuffix .h, $(NAME))
