#include "filler.h"

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
// 	best position close to opponent
// */
// int		go_close(int to_play[])
// {
// 	to_play[0] = 2;
// 	to_play[1] = 8;
// 	return (1);
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
				pos[i++].y = y;
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

int		ai_launch(t_params *params, t_coord *to_play)
{
	// t_coord		pos[params->board_size.x * params->board_size.y];
	// int			pos_size;
	// (void)params;
	// valid_position(params);
	// if((go_close(to_play)))
	// 	;
	// else if((go_edge(to_play)))
	// 	;
	// else
	// 	return (go_conced());
	// pos_size = get_possible_positions(params, pos);
	// *to_play = pos[rand() % pos_size];
	go_where_u_can(params, to_play);
	return(1);
}
