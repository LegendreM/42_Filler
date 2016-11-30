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


/*
	piece valid position in game board	
*/
// void	valid_position(t_params *params)
// {
// 	int i;
// 	int j;
// 	char** my_piece;

// 	i = 0;
// 	j = 0;

// 	while(params->game_board[i])
// 	while (params->game_board[i])
// 	{
// 		ft_putendl_fd(params->game_board[i], 2);
// 		++i;
// 	}
// }

/*
	best position close to opponent
*/
int		go_close(int to_play[])
{
	to_play[0] = 2;
	to_play[1] = 8;
	return (1);
}

/*
	if you re close to opponent go to the edge
*/
int		go_edge(int to_play[])
{
	to_play[0] = 2;
	to_play[1] = 8;
	return (1);
}

int		go_where_u_can(int to_play[])
{
	to_play[0] = 2;
	to_play[1] = 8;
	return (1);
}

int		go_conced()
{
	ft_putstr("STUPID GAME!");
	return (0);
}

int		ai_dv(t_params *params, int to_play[])
{
	(void)params;
	// valid_position(params);
	if((go_close(to_play)))
		;
	else if((go_edge(to_play)))
		;
	else if((go_where_u_can(to_play)))
		;
	else
		return (go_conced());
	return(1);
}