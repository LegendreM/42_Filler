/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:52:11 by mlegendr          #+#    #+#             */
/*   Updated: 2016/12/02 18:55:30 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			loop_hook(t_env *env)
{
	t_coord		to_play;
(void)env;
	// to_play = (int*)malloc(sizeof(int) * 2);
	// /* Parser */
	env->params = parser(env->params);
//	if (!(params = parser(env->params)))
//	{
		// ft_putendl_fd("In return", 2);
//		return (0);
//	}
	//  AI 
	if (ai_launch(env->params, &to_play))
		play(to_play.y, to_play.x);
	// draw_game_board(env->win_img, params);
	return (0);
}
