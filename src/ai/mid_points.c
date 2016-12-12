
#include "filler.h"
#include "ai_dv.h"

void 		t_coord_init(t_coord *coord)
{
	coord->x = 0;
	coord->y = 0;
}

void 		t_coord_average(t_coord *coord, int nb)
{
	coord->x /= nb;
	coord->y /= nb;
}

t_coord		mid_points(t_params *params)
{
	t_coord opp_c;
	int 	opp_size;
	t_coord check;

	t_coord_init(&opp_c);
	opp_size = 0;
	check.y = 0;
	while (check.y < params->board_size.y)
	{
		check.x = 0;
		while (check.x < params->board_size.x)
		{
			if (params->game_board[check.y][check.x] != '.')
				if (params->game_board[check.y][check.x] != params->player[0] &&\
					params->game_board[check.y][check.x] != params->player[1] && ++opp_size)
				{
					opp_c.x += check.x;
					opp_c.y += check.y;
				}
			++check.x;
		}
		++check.y;
	}
	t_coord_average(&opp_c, opp_size);
	return (opp_c);
}