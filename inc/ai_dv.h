/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_dv.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 09:14:11 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/13 09:22:23 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AI_DV_H

# define AI_DV_H

# include "filler.h"
# include "mlxlibft.h"

typedef struct	s_game_size
{
	int			opp;
	int			me;
}				t_game_size;

void			t_coord_init(t_coord *coord);

#endif
