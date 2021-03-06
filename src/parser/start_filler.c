/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_filler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:58:07 by jle-mene          #+#    #+#             */
/*   Updated: 2017/01/06 11:34:40 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_params	*init_params(t_params *params)
{
	if ((params = (t_params *)malloc(sizeof(t_params))) == NULL)
	{
		ft_putendl_fd("CANNOT MALLLOC IN INIT", 2);
		return (NULL);
	}
	params->game_board = NULL;
	params->game_piece = NULL;
	params->game_piece_min = NULL;
	params->player[0] = '\0';
	params->player[1] = '\0';
	params->player[2] = '\0';
	params->count_line = 0;
	return (params);
}

int				start_filler(void)
{
	t_coord		to_play;
	t_params	*params;

	params = NULL;
	if ((params = init_params(params)) == NULL)
		return (1);
	while (1)
	{
		params = parser(params);
		if (params->game_board != NULL && ai_launch(params, &to_play))
			play(params->piece_orig, to_play.y, to_play.x);
		else
			play((t_coord){0, 0}, INT_MIN, INT_MIN);
	}
	return (0);
}
