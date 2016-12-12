/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_dv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:32:46 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/08 13:04:18 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		go_conced()
{
	ft_putstr("STUPID GAME!");
	return (0);
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


t_coord		bsq(t_params *params)
{
	t_roi sq;
	t_roi max_sq;
	t_coord sq_mid;

	sq_mid.x = params->board_size.x / 2;
	sq_mid.y = params->board_size.y / 2;
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
			sq.width = max_sq.width;
			sq.height = max_sq.height;
			++sq.x;
		}
		++sq.y;
	}
	sq_mid.x = max_sq.x + max_sq.width / 2;
	sq_mid.y = max_sq.y + max_sq.height / 2;
	return (sq_mid);
}

int		go_space(t_coord *to_play, int pos_size, t_coord *pos, t_params *params)
{
	t_coord opp_c;
	int i;
	int dist;
	int tmp_dist;

	i = 0;
	opp_c = bsq(params);
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

int find_top(t_params *params)
{
	t_coord check;

	check.y = 0;
	while (check.y < params->board_size.y)
	{
		check.x = 0;
		while (check.x < params->board_size.x)
		{
			if (params->game_board[check.y][check.x] == params->player[0] ||\
				params->game_board[check.y][check.x] == params->player[1])
			{
				return (check.y);
			}

			++check.x;
		}
		++check.y;
	}
	return (check.y);
}

int find_bot(t_params *params)
{
	t_coord check;

	check.y = params->board_size.y - 1;
	while (check.y > -1)
	{
		check.x = 0;
		while (check.x < params->board_size.x)
		{
			if (params->game_board[check.y][check.x] == params->player[0] ||\
				params->game_board[check.y][check.x] == params->player[1])
			{
				return (check.y);
			}
			++check.x;
		}
		--check.y;
	}
	return (check.y);
}

int find_left(t_params *params)
{
	t_coord check;

	check.x = 0;
	while (check.x < params->board_size.x)
	{
		check.y = 0;
		while (check.y < params->board_size.y)
		{
			if (params->game_board[check.y][check.x] == params->player[0] ||\
				params->game_board[check.y][check.x] == params->player[1])
			{
				return (check.x);
			}
			++check.y;
		}
		++check.x;
	}
	return (check.x);
}

int find_right(t_params *params)
{
	t_coord check;

	check.x = params->board_size.x - 1;
	while (check.x > -1)
	{
		check.y = 0;
		while (check.y < params->board_size.y)
		{
			if (params->game_board[check.y][check.x] == params->player[0] ||\
				params->game_board[check.y][check.x] == params->player[1])
			{
				return (check.x);
			}
			++check.y;
		}
		--check.x;
	}
	return (check.x);
}

int check_square(t_params *params)
{
	t_roi	sq;

	sq.y = find_top(params);
	sq.height = find_bot(params) - sq.y + 1;
	sq.x = find_left(params);
	sq.width = find_right(params) - sq.x + 1;
	return (sq.height * sq.width);
}

int	easy_win_vs_qhonore(t_params *params, t_coord *pos, int pos_size, t_coord *to_play)
{
	int max;
	int i;
	int sq_size;//

	i = 0;
	max = 0;
	// *to_play = pos[0];
	while (pos_size != 0)
	{
		place_piece(params, pos[i]);
		sq_size = check_square(params);
		if (sq_size == (params->board_size.x * params->board_size.y))
			return (go_close(to_play, pos_size, pos, params));
		if (max < sq_size)
		{
			max = sq_size;
			to_play->x = pos[i].x;
			to_play->y = pos[i].y;
		}
		reset_piece(params, pos[i]);
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
	// *to_play = pos[rand() % pos_size];
	// valid_position(params);
	// if((bsq(to_play, params)))
	// 	return(1);

	// if((go_space(to_play, pos_size, pos, params)))
	// 	return(1);

	if(easy_win_vs_qhonore(params, pos, pos_size,to_play))
		return (1);

	// else if((go_edge(to_play)))
	// 	;
	// else
	// 	return (go_conced());
	// go_where_u_can(params, to_play);
	return(1);
}
