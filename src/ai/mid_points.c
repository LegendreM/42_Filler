
#include "filler.h"

t_coord		mid_points(t_params *params, char player[3])
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
				if (params->game_board[check.y][check.x] == player[0] &&\
					params->game_board[check.y][check.x] == player[1])
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