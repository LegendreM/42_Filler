#include "ai_dv.h"

static int	block_opp(t_params *params, t_coord coord, t_coord check,
				int *blocked, char opp_game_board[params->board_size.y][params->board_size.x])
{
	if (params->game_piece_min[check.y][check.x] != '.')
	{
		if (opp_game_board[check.y + coord.y][check.x + coord.x] == '*')
			++*blocked;
		else
			return (0);
	}
	return (1);
}

int		check_opp(t_params *params, char opp_game_board[params->board_size.y][params->board_size.x], t_coord coord)
{
	t_coord check;
	int		blocked;

	blocked = 0;
	check.y = 0;
	while (check.y < params->piece_size_min.y)
	{
		check.x = 0;
		while (check.x < params->piece_size_min.x)
		{
			block_opp(params, coord, check, &blocked, opp_game_board);
			++check.x;
		}
		++check.y;
	}
	return (blocked);	
}

void	opp_game_board_init(t_params *params, char opp_game_board[params->board_size.y][params->board_size.x])
{
	t_coord check;

	t_coord_init(&check);
	while (check.y < params->board_size.y)
	{
		check.x = 0;
		while (check.x < params->board_size.x)
		{
			opp_game_board[check.y][check.x] = '.';
			++check.x;
		}
		++check.y;
	}
}


int		go_pwned(t_params *params, t_game_size pos_size, t_coord *opp, t_coord *me, t_coord *to_play)
{
	char	opp_game_board[params->board_size.y][params->board_size.x];
	t_coord	check;
	int 	max_block;
	int 	tmp_block;
	int		i;
	int		ret = 0;
	i = 0;
	max_block = 0;
	tmp_block = 0;
	t_coord_init(&check);
	opp_game_board_init(params, opp_game_board);
	while (pos_size.opp != 0)
	{
		opp_game_board[opp->y][opp->x] = '*';
		--pos_size.opp;
	}
	while (pos_size.me != 0)
	{
		tmp_block = check_opp(params, opp_game_board, me[i]);
		if (tmp_block > max_block)
		{
			to_play->x = me[i].x;
			to_play->y = me[i].y;
			max_block = tmp_block;
			++ret;
		}
		++i;
		--pos_size.me;
	}
	return (ret);
}

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
	t_coord		me[params->board_size.x * params->board_size.y];
	t_coord		opp[params->board_size.x * params->board_size.y];
	t_game_size	pos_size;

	to_play->x = 0;
	to_play->y = 0;

	pos_size.me = get_possible_positions(params, me);
	opp_options(params,	&pos_size.opp, opp);
	if (go_pwned(params, pos_size, opp, me, to_play) > 0)
	{
		return (1);
	}
	else 
	{
		go_close(to_play, pos_size.me, me, params);
	}
	return (1);
}
