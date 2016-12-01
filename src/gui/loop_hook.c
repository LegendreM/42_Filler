/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:52:11 by mlegendr          #+#    #+#             */
/*   Updated: 2014/12/08 16:59:52 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			loop_hook(t_env *env)
{
	t_params	*params;
	int			to_play[2];

	to_play[0] = 2;
	to_play[1] = 8;
	params = NULL;
	// to_play = (int*)malloc(sizeof(int) * 2);
	// /* Parser */
	// if (!(params = parser()))
	// 	return (0);
	//  AI 
	// if (ai_dv(params, to_play))
	// 	play(to_play[0], to_play[1]);
	draw_game_board(env->win_img, params);
	return (0);
}