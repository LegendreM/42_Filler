NAME = wolf3d

FUNC = main parse ret_error raycast gnl/get_next_line aa_corection minimap loop_hook attempt_to_move expose check_horizontal check_vertical \
		greater tag put_tag red_cross

SRC = $(addsuffix .c, $(FUNC))

OBJ = $(addsuffix .o, $(FUNC))

CC = clang

FLAGS = -Wall -Werror -Wextra

NAME_TAR = transfer.tar

ILL = 'free'

all: lib $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $@ $^ mlxlibft/mlxlibft.a libft/libft.a -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $< -I include/ -I mlxlibft/

lib:
	@make -C libft/
	@make -C mlxlibft/

clean:
	@rm -rf $(OBJ)
	@echo "\033[91;1mObject removed\033[0m";

lclean:
	@make -C libft/ clean
	@make -C mlxlibft/ clean

aclean: clean lclean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@Make -C mlxlibft/ fclean
	@echo "\033[91;1mBinary removed\033[0m";

lfclean:
	@make -C libft/ fclean
	@make -C mlxlibft/ fclean

afclean: fclean lfclean

re: fclean all

relib: lfclean lib

rea: relib re

tar: fclean
	@echo "\033[92;1mProject compressed\033[0m";
	@tar -cf $(NAME_TAR) $(SRC) Makefile $(addsuffix .h, $(NAME))

ill:
	cat $(SRC) | grep -n $(ILL)
