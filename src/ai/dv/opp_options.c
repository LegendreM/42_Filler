#include "ai_dv.h"

int		change_player(t_params *params)
{
	if (params->player[0] == 'O')
	{
		params->player[0] = 'X';
		params->player[1] = 'x';
	}
	else if (params->player[0] == 'X')
	{
		params->player[0] = 'O';
		params->player[1] = 'o';
	}
	else
	{
		ft_putendl_fd("you're kidding me?", 2);
		return (0);
	}
	return (1);
}

void	opp_options(t_params *params, int *pos_size, t_coord *pos)
{
	change_player(params);
	*pos_size = get_possible_positions(params, pos);
	change_player(params);
}
