/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_wyki.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:49:39 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/12 15:57:41 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ai_wyki.h"

static t_axis	get_axis(t_square *me, t_square *op)
{
	int		x;
	int		y;

	x = me->center.x - op->center.x;
	y = me->center.y - op->center.y;
	x = x < 0 ? -x : x;
	y = y < 0 ? -y : y;
	return (y > x ? axis_x : axis_y);
}

static int		rush_edge(t_coord *pos, int pos_size, t_axis axis)
{
	t_coord	new_pos[2];
	int		x;

	x = 0;
	new_pos[0] = (t_coord){32000, 32000};
	new_pos[1] = (t_coord){0, 0};
	while (x < pos_size)
	{
		if (axis == axis_x && pos[x].x <= new_pos[0].x)
			new_pos[0] = pos[x];
		if (axis == axis_x && pos[x].x >= new_pos[1].x)
			new_pos[1] = pos[x];
		if (axis == axis_y && pos[x].y <= new_pos[0].y)
			new_pos[0] = pos[x];
		if (axis == axis_y && pos[x].y >= new_pos[1].y)
			new_pos[1] = pos[x];
		++x;
	}
	pos[0] = new_pos[0];
	pos[1] = new_pos[1];
	return (2);
}

static int		already_on_edges(t_params *params)
{
	t_coord	count;

	count = (t_coord){0, 0};
	count.x += check_edge(params, params->player[0],
			(t_coord){0, 0},
			(t_coord){params->board_size.x - 1, 0});
	count.x += check_edge(params, params->player[0],
			(t_coord){0, params->board_size.y - 1},
			(t_coord){params->board_size.x - 1, params->board_size.y - 1});
	count.y += check_edge(params, params->player[0],
			(t_coord){0, 0},
			(t_coord){0, params->board_size.y - 1});
	count.y += check_edge(params, params->player[0],
			(t_coord){params->board_size.x - 1, 0},
			(t_coord){params->board_size.x - 1, params->board_size.y - 1});
	return (count.x == 2 || count.y == 2 ? 1 : 0);
}

int				ai_launch(t_params *params, t_coord *to_play)
{
	t_coord		pos[params->board_size.x * params->board_size.y];
	int			pos_size;
	t_square	me;
	t_square	op;

	fill_squares(params, &me, &op);
	pos_size = get_possible_positions(params, pos);
	if (!already_on_edges(params))
	{
		pos_size = rush_edge(pos, pos_size, get_axis(&me, &op));
		*to_play = is_edge_occupied(params, pos[0]) ? pos[1] : pos[0];
	}
	else
	{
		*to_play = go_closer(params, pos, pos_size, &op);
	}
	return (1);
}
