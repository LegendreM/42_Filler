#ifndef WYKI_AI_H

# define WYKI_AI_H

# include "mlxlibft.h"

typedef enum	e_axis
{
	axis_x = 0, axis_y
}				t_axis;

typedef struct	s_square
{
	t_coord	min;
	t_coord	max;
	t_coord	size;
	t_coord	center;
	int		area;
}				t_square;

#endif
