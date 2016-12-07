/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:52:11 by mlegendr          #+#    #+#             */
/*   Updated: 2016/12/07 16:59:25 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			loop_hook(t_env *env)
{
	t_coord		to_play;

	env->params = parser(env->params);
	if (ai_launch(env->params, &to_play))
		play(env->params->piece_orig, to_play.y, to_play.x);
	draw_game_board(env->win_img, env->params);
	expose(env);
	usleep(SPEED);
	return (0);
}
