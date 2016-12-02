/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:52:11 by mlegendr          #+#    #+#             */
/*   Updated: 2016/12/02 18:46:56 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			loop_hook(t_env *env)
{
	t_coord		to_play;
(void)env;
	// to_play = (int*)malloc(sizeof(int) * 2);
	// /* Parser */
	 ft_putendl_fd("loop_hook 1", 2);
	env->params = parser(env->params);
//	if (!(params = parser(env->params)))
//	{
		// ft_putendl_fd("In return", 2);
//		return (0);
//	}
	//  AI 
	 ft_putendl_fd("Loop_hook 2", 2);
	if (ai_launch(env->params, &to_play))
		play(to_play.y, to_play.x);
	// draw_game_board(env->win_img, params);
//	sleep(1);
	 ft_putendl_fd("Loop_hook 3", 2);
//	play(8, 2);
	return (0);
}
