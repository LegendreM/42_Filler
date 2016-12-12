#ifndef AI_DV_H

# define AI_DV_H

# include "filler.h"
# include "mlxlibft.h"

typedef struct	s_game_size
{
	int			opp;
	int			me;
}				t_game_size;

void 		t_coord_init(t_coord *coord);
void	opp_options(t_params *params, int *pos_size, t_coord *pos);

#endif