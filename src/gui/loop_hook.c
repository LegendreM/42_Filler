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
	clear_image_8u(env->win_img, create_pixel_8u(0x2f, 0x2f, 0x2f, 0x00));
	draw_game_rack(env->win_img, create_pixel_8u(0x9f, 0x9f, 0x9f, 0x00),
					 20, 20);
	//draw_circle_in_roi(env->win_img, (t_roi){.x = 10, .y = 20, .width = 100, .height = 200}, create_pixel_8u(0xAf, 0x00, 0x5f, 0x00));
	draw_disk_in_roi(env->win_img, (t_roi){.x = 10, .y = 20, .width = 100, .height = 200}, create_pixel_8u(0x5f, 0x00, 0xAf, 0x00));
	/* Parser */
	if (!(params = parser()))
		return (0);
	/* AI */
	if (ai_dv(params, to_play))
		play(to_play[0], to_play[1]);
	return (0);
}