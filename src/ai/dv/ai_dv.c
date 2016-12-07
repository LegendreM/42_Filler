/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_dv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:32:46 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/07 16:01:29 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		go_conced()
{
	ft_putstr("STUPID GAME!");
	return (0);
}

t_coord		mid_points(t_params *params)
{
	t_coord opp_c;
	int opp_size;
	t_coord check;

	opp_c.x = 0;
	opp_c.y = 0;
	opp_size = 0;
	check.y = 0;
	while (check.y < params->board_size.y)
	{
		check.x = 0;
		while (check.x < params->board_size.x)
		{
			if (params->game_board[check.y][check.x] != '.')
			{
				if (params->game_board[check.y][check.x] != params->player[0] &&\
					params->game_board[check.y][check.x] != params->player[1])
				{
					opp_c.x += check.x;
					opp_c.y += check.y;
					++opp_size;
				}
			}
			++check.x;
		}
		++check.y;
	}
	opp_c.x /= opp_size;
	opp_c.y /= opp_size;
	return (opp_c);
}

int	my_sqrt(int nb)
{
	int i;
	i = 0;

	while ((i * i) < nb)
		++i;
	return (i);
}
/*
	best position close to opponent
*/
int		go_close(t_coord *to_play, int pos_size, t_coord *pos, t_params *params)
{
	t_coord opp_c;
	int i;
	int dist;
	int tmp_dist;

	i = 0;
	opp_c = mid_points(params);
	dist = my_sqrt(params->board_size.y * params->board_size.y + params->board_size.x * params->board_size.x);
	tmp_dist = dist;
	while(pos_size != 0)
	{
		tmp_dist = my_sqrt((opp_c.x - pos[i].x) * (opp_c.x - pos[i].x) + (opp_c.y - pos[i].y) * (opp_c.x - pos[i].x));
		if( dist > tmp_dist)
		{
			to_play->x = pos[i].x;
			to_play->y = pos[i].y;
			dist = tmp_dist;
		}
		++i;
		--pos_size;
	}
	return (1);
}

int		ai_launch(t_params *params, t_coord *to_play)
{
	t_coord		pos[params->board_size.x * params->board_size.y];
	int			pos_size;

	pos_size = get_possible_positions(params, pos);
	// *to_play = pos[rand() % pos_size];
	// valid_position(params);
	if((go_close(to_play, pos_size, pos, params)))
		return(1);
	// else if((go_edge(to_play)))
	// 	;
	// else
	// 	return (go_conced());
	// go_where_u_can(params, to_play);
	return(1);
}
