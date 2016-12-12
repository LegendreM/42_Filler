/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:12:25 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/12 15:19:50 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ai_wyki.h"

static void	retrieve_square(t_params *params, t_square *sq, char c)
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

static void	init_square(t_params *params, t_square *sq)
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

void		fill_squares(t_params *params, t_square *me, t_square *op)
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

int			in_square(t_coord pos, t_square *sq)
{
	if (pos.x >= sq->min.x && pos.x < sq->max.x
		&& pos.y >= sq->min.y && pos.y < sq->max.y)
		return (1);
	return (0);
}
