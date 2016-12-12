#include "ai_dv.h"

t_coord		opp_dist(t_coord *check, t_coord pos, t_params *params, int *dist)
{
	int		tmp_dist;
	t_coord to_play;

	tmp_dist = 0;
	check->x = 0;
	while (check->x < params->board_size.x)
	{
		if (params->game_board[check->y][check->x] != '.')
			if (params->game_board[check->y][check->x] != params->player[0] \
				&& params->game_board[check->y][check->x] != params->player[1])
			{
				tmp_dist = get_dist(pos, *check);
				if (*dist > tmp_dist)
				{
					to_play.x = pos.x;
					to_play.y = pos.y;
					*dist = tmp_dist;
				}
			}
		++check->x;
	}
	++check->y;
	return (to_play);
}

int			go_around(t_coord *to_play, int pos_size, \
						t_coord *pos, t_params *params)
{
	int		i;
	int		dist;
	t_coord	check;

	t_coord_init(&check);
	i = 0;
	dist = 10000;
	while (pos_size != 0)
	{
		check.y = 0;
		while (check.y < params->board_size.y)
		{
			*to_play = opp_dist(&check, pos[i], params, &dist);
		}
		++i;
		--pos_size;
	}
	return (1);
}

int			ai_launch(t_params *params, t_coord *to_play)
{
	t_coord		me[params->board_size.x * params->board_size.y];
	int			pos_size;

	to_play->x = 0;
	to_play->y = 0;
	pos_size = get_possible_positions(params, me);
	if (go_around(to_play, pos_size, me, params) > 0)
	{
		return (1);
	}
	return (1);
}
