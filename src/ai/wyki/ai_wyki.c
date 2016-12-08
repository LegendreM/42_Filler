/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_wyki.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:49:39 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/08 16:00:46 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"



int		rush_edge(t_params *params, t_coord *pos, int pos_size, t_axis axis)
{
	t_coord	new_pos[2];
	int		x;
	(void)params;

	x = 0;
	new_pos[0] = pos[0];
	new_pos[1] = pos[1];
	while (x < pos_size)
	{
		if (axis == axis_x)
		{
			if (pos[x].x < new_pos[0].x)
				new_pos[0] = pos[x];
			if (pos[x].x > new_pos[1].x)
				new_pos[1] = pos[x];
		}
		else if (axis == axis_y)
		{
			if (pos[x].y < new_pos[0].y)
				new_pos[0] = pos[x];
			if (pos[x].y > new_pos[1].y)
				new_pos[1] = pos[x];
		}
		++x;
	}
	return (2);
}

int		already_on_edges(t_params *params)
{
	t_coord	count;
	int		x;
	int		y;

	count = (t_coord){0, 0};
	y = 0;
	while (y < params->board_size.y)
	{
		x = 0;
		while (x < params->board_size.x)
		{
			if (y != 0 && y != params->board_size.y - 1)
				x =	params->board_size.x - 1;
			if (params->game_board[y][x] == params->player[0])
			{
				count.x += y == 0 || y == params->board_size.y - 1 ? 1 : 0;
				count.y += x == 0 || x == params->board_size.x - 1 ? 1 : 0;
				break ;
			}
			++x;
		}
		y++;
	}
	return (count.x == 2 || count.y == 2 ? 1 : 0);
}

t_axis		get_axis(t_square *me, t_square *op)
{
	int		x;
	int		y;

	x = me->center.x - op->center.x;
	y = me->center.y - op->center.y;
	x = x < 0 ? - x : x;
	y = y < 0 ? - y : y;
	return (y > x ? axis_x : axis_y);
}

int			get_distance(t_coord pos, t_square *sq)
{
	int		dist;
	int		x_dist;
	int		y_dist;

	x_dist = pos.x - sq->center.x;
	y_dist = pos.y - sq->center.y;
	x_dist = x_dist < 0 ? - x_dist : x_dist;
	y_dist = y_dist < 0 ? - y_dist : y_dist;
	dist = x_dist * x_dist + y_dist * y_dist;
	dist = dist / 2; // Need to change that
	return (dist);
}

/*
t_coord	get_closer_point(t_params *params, t_coord *pos, int pos_size)
{

}

t_coord	get_distance(t_params *params, t_coord *pos, int pos_size)
{
	t_coord	closer;

	closer = get_closer_point(params, pos, pos_size);
}
*/
void	retrieve_square(t_params *params, t_square *sq, char c)
{
	int		x;
	int		y;

	y = 0;
	while (y < params->board_size.y)
	{
		x = 0;
		while (x < params->board_size.x)
		{
			if (params->game_board[y][x] == c)
			{
				if (x < sq->min.x)
					sq->min.x = x;
				if (y < sq->min.y)
					sq->min.y = y;
				if (x > sq->max.x)
					sq->max.x = x;
				if (y > sq->max.y)
					sq->max.y = y;
			}
			++x;
		}
		++y;
	}
	return ;
}

void	init_square(t_params *params, t_square *sq)
{
	sq->min.x = params->board_size.x;
	sq->min.y = params->board_size.y;
	sq->max.x = 0;
	sq->max.y = 0;
	sq->size.x = 0;
	sq->size.y = 0;
	sq->center.x = 0;
	sq->center.y = 0;
	sq->area = 0;
}

void	fill_squares(t_params *params, t_square *me, t_square *op)
{
	char	me_c;
	char	op_c;

	me_c = params->player[0];
	op_c = me_c == 'O' ? 'X' : 'O';
	init_square(params, me);
	init_square(params, op);
	retrieve_square(params, me, me_c);
	retrieve_square(params, op, op_c);
	me->size.x = me->max.x - me->min.x + 1;
	me->size.y = me->max.y - me->min.y + 1;
	me->center.x = me->min.x + me->size.x / 2;
	me->center.y = me->min.y + me->size.y / 2;
	me->area = me->size.x * me->size.y;
	op->size.x = op->max.x - op->min.x + 1;
	op->size.y = op->max.y - op->min.y + 1;
	op->center.x = op->min.x + op->size.x / 2;
	op->center.y = op->min.y + op->size.y / 2;
	op->area = op->size.x * op->size.y;
}

void	print_square(t_square *sq)
{
	ft_putendl_fd("##### SQUARE #####", 2);

	ft_putstr_fd("Pos min : x=", 2);
	ft_putnbr_fd(sq->min.x, 2);
	ft_putstr_fd(" y=", 2);
	ft_putnbr_fd(sq->min.y, 2);
	ft_putendl_fd("", 2);

	ft_putstr_fd("Pos max : x=", 2);
	ft_putnbr_fd(sq->max.x, 2);
	ft_putstr_fd(" y=", 2);
	ft_putnbr_fd(sq->max.y, 2);
	ft_putendl_fd("", 2);

	ft_putstr_fd("Size : x=", 2);
	ft_putnbr_fd(sq->size.x, 2);
	ft_putstr_fd(" y=", 2);
	ft_putnbr_fd(sq->size.y, 2);
	ft_putendl_fd("", 2);

	ft_putstr_fd("Center : x=", 2);
	ft_putnbr_fd(sq->center.x, 2);
	ft_putstr_fd(" y=", 2);
	ft_putnbr_fd(sq->center.y, 2);
	ft_putendl_fd("", 2);

	ft_putstr_fd("Area : x=", 2);
	ft_putnbr_fd(sq->area, 2);
	ft_putendl_fd("", 2);

	ft_putendl_fd("##### SQUARE #####", 2);
}

int		ai_launch(t_params *params, t_coord *to_play)
{
	t_coord		pos[params->board_size.x * params->board_size.y];
	int			pos_size;
	t_square	me;
	t_square	op;

	fill_squares(params, &me, &op);
	print_square(&me);
	print_square(&op);
	pos_size = get_possible_positions(params, pos);
	if (!already_on_edges(params))
	{
		pos_size = rush_edge(params, pos, pos_size, get_axis(&me, &op));
		*to_play = get_distance(pos[0], &op) > get_distance(pos[1], &op) ? pos[1] : pos[0];
	}
	else
	{
		*to_play = pos_size != 0 ? pos[rand() % pos_size] : (t_coord){0, 0};
	}
	return(1);
}
