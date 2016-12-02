/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:21:13 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/02 18:45:26 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_init_board(char *start, t_params *params)
{
	ft_putendl_fd("Init board", 2);
	int i;

	i = 0;
	while(ft_isalpha(start[i]))
		++i;
	++i;
	params->board_size.y = ft_atoi(&start[i]);
	while(ft_isdigit(start[i]))
		++i;
	params->board_size.x = ft_atoi(&start[i]);
	params->game_board = ft_matrixnew(params->board_size.y,
							params->board_size.x);
	return ;
//	return (params);
}

t_params	*ft_init_params(t_params *params)
{
		ft_putendl_fd("Init params 1", 2);
	params = (t_params*)malloc(sizeof(t_params));
	params->game_board = NULL;
	params->game_piece = NULL;
	params->game_piece_min = NULL;
	params->player[0] = 0;
	params->count_line = 0;
		ft_putendl_fd("Init params 2", 2);
	return (params);
}

void	ft_player_number(char *start, t_params *params)
{
	ft_putendl_fd("Assign player", 2);
	if (ft_strstr((const char*)start, "$$$ exec p1 :"))
	{
		ft_putendl_fd("Enter p1", 2);
		params->player[0] = 'O';
		params->player[1] = 'o';
	}
	else if (ft_strstr((const char*)start, "$$$ exec p2 :"))
	{
		ft_putendl_fd("Enter p2", 2);
		params->player[0] = 'X';
		params->player[1] = 'x';
	}
	return ;
/*
	if (ft_atoi(&start[-4]) == 1)
		params->player = 'o';
	else if (ft_atoi(&start[-4]) == 2)
		params->player = 'x';
	else
		return (-1);
	return (0);
	*/
}

void		ft_fill_matrix(const char *line, t_params *params)
{
	ft_strncpy(
		params->game_board[params->count_line],
		line + 4,
		params->board_size.x
	);
	params->count_line++;
}

int			ft_check_input(char *str, t_params **params)
{
	int i;
	char* start;

	i = 0;
	if (str)
	{
		if (*params == NULL)
		{
			*params = ft_init_params(*params);
		}
		if (*params != NULL && (*params)->game_board == NULL
			&& (start = ft_strstr((const char*)str, "Plateau ")))
		{
			ft_init_board(start, *params);
		}
		if (*params != NULL && (*params)->player[0] == 0
			&& (start = ft_strstr((const char*)str, PLAYER_NAME)))
		{
			ft_player_number(str, *params);
		}
		if (ft_isdigit(str[0]))
		{
			ft_fill_matrix((const char *)str, *params);
		}
		if ((start = ft_strstr((const char*)str, "Piece ")))
		{
			ft_get_piece(start, *params);
			return (0);
	//			play(0, 0);
		}
	}
	return (1);
}

void		print_matrix(char **map, t_coord size)
{
	int		y;

	y = 0;
	while (y < size.y)
	{
		write(2, map[y++], size.x);
		write(2, "\n", 1);
	}
}

t_params	*parser(t_params *params)
{
	char		*line;
	char		*map;
	int			ret;

	ft_putendl_fd("Parser1", 2);
	if (params != NULL)
		params->count_line = 0;
	if (!(map = ft_strnew(BUFFSIZE)))
		return NULL;
	ft_putendl_fd("Parser2", 2);
	while ((ret = get_next_line(FD, &line)) > 0)
	{
		ft_putendl_fd("Parser3", 2);
		ft_putendl_fd(line, 2);
		if (ft_check_input(line, &params) == 0)
			break;
	}
		ft_putendl_fd("Parser4", 2);
	ft_putendl_fd(" ", 2);
	ft_putchar_fd(params->player[0], 2);
	ft_putchar_fd(params->player[1], 2);
	ft_putendl_fd(" ", 2);
	// It returns a filled matrix, now need to check if it works multiple times
	if (params != 0)
	{
		print_matrix(params->game_board, params->board_size);
		print_matrix(params->game_piece, params->piece_size);
		print_matrix(params->game_piece_min, params->piece_size_min);
	}
	return params;
}
