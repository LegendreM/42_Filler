/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game_rack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:23:13 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/12 16:23:15 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	t_roi	*save_cases(const t_coord rack_size,
							const t_roi roi)
{
	t_roi			*rack;
	int				i;
	t_coord			coord;
	const t_coord	case_size = {.x = roi.width / rack_size.x,

	.y = roi.height / rack_size.y};
	coord.x = roi.x;
	coord.y = roi.y;
	rack = (t_roi*)malloc(sizeof(t_roi) * rack_size.x * rack_size.y);
	i = 0;
	while (i < rack_size.x * rack_size.y)
	{
		if (coord.x >= rack_size.x * case_size.x + roi.x)
		{
			coord.y += case_size.y;
			coord.x = roi.x;
		}
		rack[i].x = coord.x;
		rack[i].y = coord.y;
		rack[i].width = case_size.x;
		rack[i].height = case_size.y;
		coord.x += case_size.x;
		++i;
	}
	return (rack);
}

t_roi			*draw_game_rack(t_mlx_image_8u *dst,
								const t_pixel_8u pixel,
								const int rack_width,
								const int rack_height)
{
	const int		ww = dst->width;
	const int		wh = dst->height;
	const t_coord	rack_size = {.x = rack_width, .y = rack_height};
	const t_roi		roi = create_roi(ww / 10, wh / 10,

	ww * 8 / 10, wh * 8 / 10);
	draw_rack(dst, roi, pixel, rack_size);
	return (save_cases(rack_size, roi));
}
