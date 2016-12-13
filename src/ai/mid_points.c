/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:11:52 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/12 17:26:49 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "ai_dv.h"

static	void		t_coord_average(t_coord *coord, int nb)
{
	coord->x /= nb;
	coord->y /= nb;
}

t_coord				mid_points(t_params *params)
{
	t_coord opp_c;
	int		opp_size;
	t_coord check;

	t_coord_init(&opp_c);
	opp_size = 0;
	check.y = -1;
	while (++check.y < params->board_size.y)
	{
		check.x = -1;
		while (++check.x < params->board_size.x)
			if (params->game_board[check.y][check.x] != '.')
				if (params->game_board[check.y][check.x] != params->player[0]\
				&& params->game_board[check.y][check.x] != params->player[1])
				{
					opp_c.x += check.x;
					opp_c.y += check.y;
					++opp_size;
				}
	}
	t_coord_average(&opp_c, opp_size);
	return (opp_c);
}
