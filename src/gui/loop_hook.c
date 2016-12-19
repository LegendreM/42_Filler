/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 09:35:05 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/19 09:08:56 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			loop_hook(t_env *env)
{
	t_coord		to_play;

	env->params = parser(env->params);
	if (env->params->game_board != NULL && ai_launch(env->params, &to_play))
		play(env->params->piece_orig, to_play.y, to_play.x);
	else
		play((t_coord){0, 0}, INT_MIN, INT_MIN);
	draw_game_board(env->win_img, env->params);
	expose(env);
	usleep(SPEED);
	return (0);
}
