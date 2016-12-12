/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_edge_occupied.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:54:06 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/12 15:54:43 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ai_wyki.h"

static int	check_piece_edge(t_params *params, t_coord pos)
{
	int		ret;
	t_coord	coor;

	ret = 0;
	coor = params->board_size;
	if (pos.y == 0 && pos.x >= 0 && pos.x < coor.x)
		ret += check_edge(params, params->player[0], (t_coord){0, 0},
				(t_coord){coor.x - 1, 0});
	if (pos.y == coor.y - 1 && pos.x >= 0 && pos.x < coor.x)
		ret += check_edge(params, params->player[0], (t_coord){0, coor.y - 1},
				(t_coord){coor.x - 1, coor.y - 1});
	if (pos.x == 0 && pos.y >= 0 && pos.y < coor.y)
		ret += check_edge(params, params->player[0], (t_coord){0, 0},
				(t_coord){0, coor.y - 1});
	if (pos.x == coor.x - 1 && pos.y >= 0 && pos.y < coor.y)
		ret += check_edge(params, params->player[0], (t_coord){coor.x - 1, 0},
				(t_coord){coor.x - 1, coor.y - 1});
	return (ret);
}

int			is_edge_occupied(t_params *params, t_coord pos)
{
	int		x;
	int		y;

	y = 0;
	while (y < params->piece_size_min.y)
	{
		x = 0;
		while (x < params->piece_size_min.x)
		{
			if (params->game_piece_min[y][x]
					== '*'
				&& check_piece_edge(params,
					(t_coord){.x = pos.x + x, .y = pos.y + y}))
				return (1);
			++x;
		}
		++y;
	}
	return (0);
}
