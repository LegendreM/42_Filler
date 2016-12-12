/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:11:52 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/12 17:20:46 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	init(t_coord *coor, t_coord *coor2, int *i)
{
	coor->x = 0;
	coor->y = 0;
	coor2->y = 0;
	*i = 0;
	return ;
}

t_coord		mid_points(t_params *params, char player[3])
{
	t_coord	opp_c;
	int		opp_size;
	t_coord	check;

	init(&opp_c, &check, &opp_size);
	while (check.y < params->board_size.y)
	{
		check.x = 0;
		while (check.x < params->board_size.x)
		{
			if (params->game_board[check.y][check.x] != '.')
				if (params->game_board[check.y][check.x] == player[0] &&\
					params->game_board[check.y][check.x] == player[1])
				{
					opp_c.x += check.x;
					opp_c.y += check.y;
					++opp_size;
				}
			++check.x;
		}
		++check.y;
	}
	opp_c.x /= opp_size;
	opp_c.y /= opp_size;
	return (opp_c);
}
