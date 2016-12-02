/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:52:11 by mlegendr          #+#    #+#             */
/*   Updated: 2016/12/02 17:44:54 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			loop_hook(t_env *env)
{
	t_params	*params;
	t_coord		to_play;
(void)env;
	// to_play = (int*)malloc(sizeof(int) * 2);
	// /* Parser */
	// ft_putendl_fd("Pouet 1", 2);
	if (!(params = parser()))
	{
		// ft_putendl_fd("In return", 2);
		return (0);
	}
	//  AI 
	if (ai_launch(params, &to_play))
		play(to_play.y, to_play.x);
	// draw_game_board(env->win_img, params);
//	sleep(1);
	// ft_putendl_fd("Pouet 2", 2);
//	play(to_play[0], to_play[1]);
	return (0);
}
