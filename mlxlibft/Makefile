#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/15 14:40:21 by mlegendr          #+#    #+#              #
#    Updated: 2016/09/05 14:40:06 by mlegendr         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = mlxlibft.a

SRC = 	new_mlx_image_8u.c pixel_8u.c red_8u.c green_8u.c blue_8u.c alpha_8u.c \
		free_mlx_image_8u.c new_mlx_xpm_image_8u.c get_pixel_8u.c new_pixel_8u.c \
		draw_square.c build_roi.c red_cross.c

OBJS = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -Wconversion

HEADER = libft.h

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC) -I $(HEADER) 
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
