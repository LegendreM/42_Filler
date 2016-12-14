/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_wyki.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 09:13:32 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/13 09:13:34 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AI_WYKI_H

# define AI_WYKI_H

# include "filler.h"
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

void			fill_squares(t_params *params, t_square *me, t_square *op);
int				in_square(t_coord pos, t_square *sq);

t_coord			go_closer(t_params *params, t_coord *pos, int pos_size,
				t_square *op);

int				check_edge(t_params *params, char c, t_coord orig, t_coord end);

int				is_edge_occupied(t_params *params, t_coord pos);

#endif
