#include "filler.h"
#include <math.h>//
// typedef struct	s_params
// {
// 	char		player;
// 	int			count_line;
// 	char		**game_board;
// 	char		**game_piece_min;
// 	t_coord		board_size;
// 	t_coord		piece_size_min;
// 	t_coord		coord;
// }				t_params;


int		is_valid_position2(t_params *params, t_coord coord)
{
	if ((coord.x + params->piece_size_min.x) > params->board_size.x || \
		(coord.y + params->piece_size_min.y) > params->board_size.y)
	{
		return (0);
	}
	return(1);
}

int		is_valid_position(t_params *params, t_coord coord)
{
	t_coord check;
	int warning;

	warning = 0;
	check.y = 0;
	if(is_valid_position2(params, coord))
		while (check.y < params->piece_size_min.y)
		{
			check.x = 0;
			while (check.x < params->piece_size_min.x)
			{
				if (params->game_piece_min[check.y][check.x] != '.')
					if (params->game_board[check.y + coord.y][check.x + coord.x] != '.')
					{
						if (params->game_board[check.y + coord.y][check.x + coord.x] == params->player[0] ||\
							params->game_board[check.y + coord.y][check.x + coord.x] == params->player[1])
								++warning;
						else
							return (0);
					}
				if (warning > 1)
					return (0);
				++check.x;
			}
			++check.y;
		}
	return(warning);
}

// /*
// 	piece valid position in game board	
// */
// void	valid_position(t_params *params)
// {
// 	int i;
// 	int j;
// 	int	piece_x;
// 	int	piece_y;
// 	char** my_piece;

// 	i = 0;
// 	j = 0;
// 	my_piece = ft_matrixnew(params->piece_size_min.y, params->piece_size_min.x);

// 	while (params->game_board[i])
// 	{
// 			ft_putendl_fd(params->game_board[i], 2);
// 		++i;
// 	}
// }

// int		check_dist()
// {

// }

// /*
// 	if you re close to opponent go to the edge
// */
// int		go_edge(int to_play[])
// {
// 	to_play[0] = 2;
// 	to_play[1] = 8;
// 	return (1);
// }

int		go_where_u_can(t_params *params, t_coord *to_play)
{
	int	x;
	int y;

	to_play->x = 0;
	to_play->y = 0;
	y = 0;
	while (y < params->board_size.y)
	{
		x = 0;
		while (x < params->board_size.x)
		{
			if (is_valid_position(params, (t_coord){.x = x, .y = y}))
			{
				to_play->x = x + params->piece_orig.x;
				to_play->y = y + params->piece_orig.y;
				return (1);
			}
			++x;
		}
	++y;
	}
	return (0);
}

int		get_possible_positions(t_params *params, t_coord *pos)
{
	int	x;
	int y;
	int	i;

	y = 0;
	i = 0;
	while (y < params->board_size.y)
	{
		x = 0;
		while (x < params->board_size.x)
		{
			if (is_valid_position(params, (t_coord){.x = x, .y = y}))
			{
				pos[i].x = x;
				pos[i].y = y;
				++i;
//				to_play->x = x;
//				to_play->y = y;
//				return (1);
			}
			++x;
		}
		++y;
	}
	return (i);
}

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
			to_play->x = pos[i].x + params->piece_orig.x;
			to_play->y = pos[i].y + params->piece_orig.y;
			dist = tmp_dist;
		}
		++i;
		--pos_size;
	}
	return (1);
}

t_roi	test_sq(t_roi sq, t_params *params)
{
	t_coord coord;
	const char **gb = (const char**)params->game_board;

	if (sq.y + sq.height > params->board_size.y ||\
		sq.x + sq.width > params->board_size.x)
		return (sq);
	coord.y = 0;
	while (coord.y < sq.width)
	{
		coord.x = 0;
		while (coord.y < sq.width)
		{
			if (gb[coord.y + sq.y][coord.x + sq.x] != '.')
				return (sq);
			++coord.x;
		}
		++coord.y;
	}
	++sq.width;
	++sq.height;
	return (test_sq(sq, params));
}


int		bsq(t_coord *to_play, t_params *params)
{
	t_roi sq;
	t_roi max_sq;
	sq = create_roi(0, 0, 1, 1);
	max_sq = create_roi(0, 0, 0, 0);

	sq.y = 0;
	while (sq.y < params->board_size.y)
	{
	 	sq.x = 0;
		while (sq.x < params->board_size.x)
		{
			sq = test_sq(sq, params);
			if (sq.width * sq.height > max_sq.width * max_sq.height)
				max_sq = sq;
			sq = max_sq;
			++sq.x;
		}
		++sq.y;
	}
	to_play->x = max_sq.x + max_sq.width / 2;
	to_play->y = max_sq.y + max_sq.height / 2;
	return (1);
}

// int		go_space(t_coord *to_play, int pos_size, t_coord *pos, t_params *params)
// {
// 	return (1);
// }


int		ai_launch(t_params *params, t_coord *to_play)
{
	t_coord		pos[params->board_size.x * params->board_size.y];
	int			pos_size;

	pos_size = get_possible_positions(params, pos);
	// *to_play = pos[rand() % pos_size];
	// valid_position(params);
	if((bsq(to_play, params)))
		return(1);

	// if((go_close(to_play, pos_size, pos, params)))
	// 	return(1);
	// else if((go_edge(to_play)))
	// 	;
	// else
	// 	return (go_conced());
	// go_where_u_can(params, to_play);
	return(1);
}
