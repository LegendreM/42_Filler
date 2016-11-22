NAME	= libftprintf.a

SRC_NM	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strcpy.c \
	ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
	ft_isdigit.c ft_isalnum.c ft_putnbr.c ft_putstr.c ft_putchar.c ft_isprint.c \
	ft_strdup.c ft_tolower.c ft_toupper.c ft_memalloc.c ft_memdel.c ft_strnew.c \
	ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_isascii.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl.c ft_putnbr_fd.c ft_itoa.c ft_strsplit.c \
	ft_putendl_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	ft_strndup.c ft_nstrdup.c ft_litoa.c ft_ullitoa.c ft_llitoa.c ft_intlen.c ft_lstrev.c \
	ft_stradd.c ft_strradd.c ft_strcharadd.c ft_strrcharadd.c ft_strnfill.c \
	ft_printf.c char_subft.c decimal_subft.c decimal2_subft.c hexa_binary_conversions.c hexadecimal_binary_subft.c\
	octal_subft.c diece_subft.c prcnt_subft.c ft_fill_format.c ft_check_format_error.c \
	ft_check_dollar.c ft_authorized_char.c ft_check_minus.c ft_check_plus.c ft_check.c\
	ft_findflag.c ft_count_letter.c ft_check_space.c ft_is_valid_alpha.c ft_parse.c \
	format.c ft_precision.c ft_init.c parse_str.c ft_wchar.c trim_zero.c

SRC_DIR	= ./src/
INC_DIR	= ./inc/

SRC		= $(addprefix $(SRC_DIR), $(SRC_NM))
OBJ		= $(SRC:.c=.o)

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -g

LIBCC	= ar rc


all: $(NAME)

$(NAME): $(OBJ)
	$(LIBCC) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ -c $<

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	
re: fclean all

.PHONY: clean fclean
#.SILENT: