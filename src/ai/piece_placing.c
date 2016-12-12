/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_placing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:21:17 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/12 17:22:19 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	place_piece(t_params *params, t_coord coord)
{
	t_coord pc;

	pc.y = 0;
	while (pc.y < params->piece_size_min.y)
	{
		pc.x = 0;
		while (pc.x < params->piece_size_min.x)
		{
			if (params->game_board[coord.y + pc.y][coord.x + pc.x] == '.' &&\
				params->game_piece_min[pc.y][pc.x] == '*')
				params->game_board[coord.y + pc.y][coord.x + pc.x] =
					params->player[1];
			++pc.x;
		}
		++pc.y;
	}
	return (1);
}

int	reset_piece(t_params *params, t_coord coord)
{
	t_coord pc;

	pc.y = 0;
	while (pc.y < params->piece_size_min.y)
	{
		pc.x = 0;
		while (pc.x < params->piece_size_min.x)
		{
			if (params->game_board[coord.y + pc.y][coord.x + pc.x] ==
					params->player[1])
				params->game_board[coord.y + pc.y][coord.x + pc.x] = '.';
			++pc.x;
		}
		++pc.y;
	}
	return (1);
}
