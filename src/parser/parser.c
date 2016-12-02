/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:21:13 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/02 17:35:08 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_params	*ft_init_board(char *start, t_params *params) //work
{
	int i;

	i = 0;
	params = (t_params*)malloc(sizeof(t_params));
	while(ft_isalpha(start[i]))
		++i;
	++i;

	params->board_size.y = ft_atoi(&start[i]);
	while(ft_isdigit(start[i]))
		++i;
	params->board_size.x = ft_atoi(&start[i]);
	params->game_board = ft_matrixnew(params->board_size.y,
							params->board_size.x);
	params->game_piece = NULL;
	params->game_piece_min = NULL;
	params->player = 0;
	params->count_line = 0;
	return (params);
}

int	ft_player_number(char *start, t_params *params) //work
{

	if (ft_atoi(&start[-4]) == 1)
		params->player = 'o';
	else if (ft_atoi(&start[-4]) == 2)
		params->player = 'x';
	else
		return (-1);
	return (0);
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
		if (*params == NULL && (start = ft_strstr((const char*)str, "Plateau ")))
		{
			*params = ft_init_board(start, *params);
		}
		if (*params != NULL && (*params)->player == 0 && (start = ft_strstr((const char*)str, PLAYER_NAME)))
		{
			ft_player_number(start, *params);
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

t_params	*parser(void)
{
	char		*line;
	char		*map;
	t_params	*params;
	int			ret;

	params = NULL;
	if (!(map = ft_strnew(BUFFSIZE)))
		return NULL;
	while ((ret = get_next_line(FD, &line)) > 0) //gnl have issues
	{
		if (ft_check_input(line, &params) == 0)
			break;
	}
	// It returns a filled matrix, now need to check if it works multiple times
	if (params != 0)
	{
		print_matrix(params->game_board, params->board_size);
		print_matrix(params->game_piece, params->piece_size);
		print_matrix(params->game_piece_min, params->piece_size_min);
	}
	return params;
}
