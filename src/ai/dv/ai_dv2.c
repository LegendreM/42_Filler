#include "filler.h"

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

int		get_dist(t_coord start_point, t_coord end_point)
{
	int dist;

	dist = my_sqrt((start_point.x - end_point.x) * (start_point.x - end_point.x)\
				+ (start_point.y - end_point.y) * (start_point.y - end_point.y));
	return (dist);
}

int		go_close(t_coord *to_play, int pos_size, t_coord *pos, t_params *params)
{
	t_coord opp_c;
	int i;
	int dist;
	int tmp_dist;

	i = 0;
	opp_c = mid_points(params);
	dist = get_dist((t_coord){.x = 0, .y = 0}, params->board_size);
	tmp_dist = dist;
	while(pos_size != 0)
	{
		tmp_dist = get_dist(pos[i], opp_c);
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
	// int i = 0;

	to_play->x = 0;
	to_play->y = 0;

	pos_size = get_possible_positions(params, pos);

	if((go_close(to_play, pos_size, pos, params)))
		return(1);
	return(1);
}
