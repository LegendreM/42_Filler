#include "filler.h"

// typedef struct	s_params
// {
// 	char		player;
// 	int			count_line;
// 	char		**game_board;
// 	char		**game_piece;
// 	t_coord		board_size;
// 	t_coord		piece_size;
// 	t_coord		coord;
// }				t_params;


int		is_valid_position(t_params *params, t_coord coord)
{
	int x;
	int y;
	int warning;

	warning = 0;
	y = 0;
	if (coord.x + params->piece_size.x > params->board_size.x || \
		coord.y + params->piece_size.y > params->board_size.y)
		return (0);
	while (y < params->piece_size.y)
	{
		x = 0;
		while (x < params->piece_size.x)
		{
			if (params->game_board[y + coord.y][x + coord.x] != '.')
				if (params->game_piece[y][x] != '.')
					++warning;
			if (warning > 1)
				return(0);
			++x;
		}
		++y;
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
// 	my_piece = ft_matrixnew(params->piece_size.y, params->piece_size.x);

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

	y = 0;
	while (y < params->board_size.y)
	{
		x = 0;
		while(x < params->board_size.x)
		{	
			if(is_valid_position(params, (t_coord){.x = x, .y = y}))
			{
				to_play->x = x;
				to_play->y = y;
				return (1);
			}
			++x;
		}
	++y;
	}
	return (0);
}

int		go_conced()
{
	ft_putstr("STUPID GAME!");
	return (0);
}

int		ai_dv(t_params *params, t_coord *to_play)
{
	// (void)params;
	// valid_position(params);
	// if((go_close(to_play)))
	// 	;
	// else if((go_edge(to_play)))
	// 	;
	// else
	// 	return (go_conced());
	go_where_u_can(params, to_play);
	return(1);
}