/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_wyki.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:49:39 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/07 15:56:11 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ai_launch(t_params *params, t_coord *to_play)
{
	t_coord		pos[params->board_size.x * params->board_size.y];
	int			pos_size;

	pos_size = get_possible_positions(params, pos);
	ft_putnbr_fd(pos_size, 2);
	ft_putendl_fd(" is the pos_size", 2);
	*to_play = pos_size != 0 ? pos[rand() % pos_size] : (t_coord){0, 0};
	return(1);
}
