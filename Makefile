NAME = fillit

FUNC = main gnl/get_next_line loop_hook expose

SRC = $(addsuffix .c, $(FUNC))

OBJ = $(addsuffix .o, $(FUNC))

CC = clang

FLAGS = -Wall -Werror -Wextra

NAME_TAR = transfer.tar

ILL = 'free'

all: lib $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $@ $^ mlxlibft/mlxlibft.a libft/libftprintf.a -lmlx -framework OpenGL -framework AppKit

%.o: src/%.c
	@$(CC) $(FLAGS) -o $@ -c $< -I inc/ -I mlxlibft/

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
