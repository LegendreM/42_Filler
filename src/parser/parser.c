/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:21:13 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/07 13:59:48 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_player(char *line, t_params *params)
{
	if (ft_strstr((const char*)line, "$$$ exec p1 :"))
	{
		params->player[0] = 'O';
		params->player[1] = 'o';
	}
	else if (ft_strstr((const char*)line, "$$$ exec p2 :"))
	{
		params->player[0] = 'X';
		params->player[1] = 'x';
	}
	return ;
}

void		set_board_size(char *line, t_params *params)
{
	int		i;

	i = 0;
	while(ft_isalpha(line[i]))
		++i;
	++i;
	params->board_size.y = ft_atoi(line + i);
	while(ft_isdigit(line[i]))
		++i;
	params->board_size.x = ft_atoi(line + i);
	params->game_board = ft_matrixnew(params->board_size.y,
							params->board_size.x);
	return ;
}

void		set_board(char *line, t_params *params)
{
	int		y;

	if (params->game_board == NULL)
		set_board_size(line, params);
	y = params->board_size.y;
	get_next_line(FD, &line);
	free(line);
	while (y > 0)
	{
		get_next_line(FD, &line);
		ft_strncpy(
				params->game_board[params->board_size.y - y],
				line + 4,
				params->board_size.x);
		free(line);
		--y;
	}
	return ;
}

static t_coord	find_piece_min_origin(char **piece, const t_coord size)
{
	t_coord	orig;
	int		x;
	int		y;

	orig.x = 1;
	orig.y = 1;
	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			if (piece[y][x] == '*')
			{
				if (-x > orig.x || orig.x == 1)
					orig.x = -x;
				if (-y > orig.y || orig.y == 1)
					orig.y = -y;
			}
			x++;
		}
		y++;
	}
	return (orig);
}

static t_coord	find_piece_min_size(char **piece, const t_coord size,
			const t_coord orig)
{
	int		x;
	int		y;
	t_coord	size_min;

	size_min.x = 0;
	size_min.y = 0;
	y = -orig.y;
	while (y < size.y)
	{
		x = -orig.x;
		while (x < size.x)
		{
			if (piece[y][x] == '*')
			{
				if (y + 1 + orig.y > size_min.y)
					size_min.y = y + 1 + orig.y;
				if (x + 1 + orig.x > size_min.x)
					size_min.x = x + 1 + orig.x;
			}
			x++;
		}
		y++;
	}
	return (size_min);
}

void		set_piece_min(t_params *params)
{
	int		y;

	if (params->game_piece_min != NULL)
		ft_matrixdel(params->game_piece_min);
	params->piece_orig = find_piece_min_origin(params->game_piece,
							params->piece_size);
	params->piece_size_min = find_piece_min_size(params->game_piece,
								params->piece_size,
								(const t_coord)params->piece_orig);
	params->game_piece_min = ft_matrixnew(params->piece_size_min.y,
								params->piece_size_min.x);
	y = 0;
	while (y < params->piece_size_min.y)
	{
		ft_strncpy(
				params->game_piece_min[y],
				params->game_piece[y - params->piece_orig.y]
					- params->piece_orig.x,
				params->piece_size_min.x);
		++y;
	}
	return ;
}

void		set_piece_size(char *line, t_params *params)
{
	int		i;

	i = 0;
	while(ft_isalpha(line[i]))
		++i;
	++i;
	params->piece_size.y = ft_atoi(line + i);
	while(ft_isdigit(line[i]))
		++i;
	params->piece_size.x = ft_atoi(line + i);
	params->game_piece = ft_matrixnew(params->piece_size.y,
							params->piece_size.x);
	return ;
}

void		set_piece(char *line, t_params *params)
{
	int		y;

	if (params->game_piece != NULL)
		ft_matrixdel(params->game_piece);
	set_piece_size(line, params);
	y = params->piece_size.y;
	while (y > 0)
	{
		get_next_line(FD, &line);
		ft_strncpy(
				params->game_piece[params->piece_size.y - y],
				line,
				params->piece_size.x);
		free(line);
		--y;
	}
	set_piece_min(params);
	return ;
}

static int	check_input(char *line, t_params *params)
{
	int		i;

	i = 0;
	if (line != NULL)
	{
		if (params->player[0] == '\0'
				&& ft_strstr((const char *)line, "$$$ exec") != NULL)
			set_player(line, params);
		else if (ft_strstr((const char *)line, "Plateau"))
			set_board(line, params);
		else if (ft_strstr((const char *)line, "Piece"))
		{
			set_piece(line, params);
			return (0);
		}
	}
	return (1);
}

static void	print_matrix(char **map, t_coord size)
{
	int		y;

	y = 0;
	while (y < size.y)
	{
		write(2, map[y++], size.x);
		write(2, "\n", 1);
	}
}

void	print_params(t_params *params)
{
	ft_putendl_fd("##### PRINT PARAMS #####", 2);

	ft_putstr_fd("Player : ", 2);
	ft_putendl_fd(params->player, 2);

	ft_putstr_fd("Board size : y=", 2);
	ft_putnbr_fd(params->board_size.y, 2);
	ft_putstr_fd(" x=", 2);
	ft_putnbr_fd(params->board_size.x, 2);
	ft_putendl_fd("", 2);
	print_matrix(params->game_board, params->board_size);

	ft_putstr_fd("Piece size : y=", 2);
	ft_putnbr_fd(params->piece_size.y, 2);
	ft_putstr_fd(" x=", 2);
	ft_putnbr_fd(params->piece_size.x, 2);
	ft_putendl_fd("", 2);
	print_matrix(params->game_piece, params->piece_size);

	ft_putstr_fd("Piece size min : y=", 2);
	ft_putnbr_fd(params->piece_size_min.y, 2);
	ft_putstr_fd(" x=", 2);
	ft_putnbr_fd(params->piece_size_min.x, 2);
	ft_putendl_fd("", 2);
	ft_putstr_fd("Piece size orig : y=", 2);
	ft_putnbr_fd(params->piece_orig.y, 2);
	ft_putstr_fd(" x=", 2);
	ft_putnbr_fd(params->piece_orig.x, 2);
	ft_putendl_fd("", 2);
	print_matrix(params->game_piece_min, params->piece_size_min);

	ft_putendl_fd("########################", 2);
}

t_params	*parser(t_params *params)
{
	char		*line;

	while (get_next_line(FD, &line))
	{
		if (check_input(line, params) == 0)
			break ;
		free(line);
	}
	free(line);

	// It returns a filled matrix, now need to check if it works multiple times
	if (params != 0)
	{
	//	print_params(params);
	}
	return params;
}
