#include "filler.h"

int		go_close(t_coord *to_play, int pos_size, t_coord *pos, t_params *params)
{
	t_coord opp_c;
	int		i;
	int		dist;
	int		tmp_dist;

	i = 0;
	opp_c = mid_points(params);
	dist = get_dist((t_coord){.x = 0, .y = 0}, params->board_size);
	tmp_dist = dist;
	while (pos_size != 0)
	{
		tmp_dist = get_dist(pos[i], opp_c);
		if (dist > tmp_dist)
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

	to_play->x = 0;
	to_play->y = 0;
	pos_size = get_possible_positions(params, pos);
	if ((go_close(to_play, pos_size, pos, params)))
		return (1);
	return (1);
}
