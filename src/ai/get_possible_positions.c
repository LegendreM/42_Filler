/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_possible_positions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:18:25 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/07 15:39:18 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	piece_fit_position(t_params *params, t_coord coord, t_coord check,
				int *warning)
{
	if (params->game_piece_min[check.y][check.x] != '.'
		&& params->game_board[check.y + coord.y]
			[check.x + coord.x] != '.')
	{
		if (params->game_board[check.y + coord.y]
				[check.x + coord.x] == params->player[0]
			|| params->game_board[check.y + coord.y]
				[check.x + coord.x] == params->player[1])
			++*warning;
		else
			return (0);
	}
	if (*warning > 1)
		return (0);
	return (1);
}

static int	piece_fit_in_board(t_params *params, t_coord coord)
{
	if ((coord.x + params->piece_size_min.x) > params->board_size.x
		|| (coord.y + params->piece_size_min.y) > params->board_size.y)
	{
		return (0);
	}
	return (1);
}

static int	is_valid_position(t_params *params, t_coord coord)
{
	t_coord check;
	int		warning;

	warning = 0;
	check.y = 0;
	if (piece_fit_in_board(params, coord))
		while (check.y < params->piece_size_min.y)
		{
			check.x = 0;
			while (check.x < params->piece_size_min.x)
			{
				if (piece_fit_position(params, coord, check, &warning) == 0)
					return (0);
				++check.x;
			}
			++check.y;
		}
	return (warning);
}

int			get_possible_positions(t_params *params, t_coord *pos)
{
	int	x;
	int y;
	int	i;

	y = 0;
	i = 0;
	while (y < params->board_size.y)
	{
		x = 0;
		while (x < params->board_size.x)
		{
			if (is_valid_position(params, (t_coord){.x = x, .y = y}))
			{
				pos[i].x = x;
				pos[i].y = y;
				++i;
			}
			++x;
		}
		++y;
	}
	return (i);
}
