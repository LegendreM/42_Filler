/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:41:22 by mlegendr          #+#    #+#             */
/*   Updated: 2016/06/02 15:41:24 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxlibft.h"

void	draw_rack(t_mlx_image_8u *dst,
				const t_roi roi,
				const t_pixel_8u pixel,
				const t_coord rack_size)
{
	t_coord			img_coord;
	t_coord			rack_coord;
	const t_coord	case_size = {.x = roi.width / rack_size.x,

	.y = roi.height / rack_size.y};
	img_coord.x = roi.x;
	img_coord.y = roi.y;
	rack_coord.y = 0;
	while (rack_coord.y <= rack_size.y)
	{
		draw_square(dst, create_roi(img_coord.x, img_coord.y,
					case_size.x * rack_size.x + 1, 1), pixel);
		img_coord.y += case_size.y;
		++rack_coord.y;
	}
	img_coord.y = roi.y;
	rack_coord.x = 0;
	while (rack_coord.x <= rack_size.x)
	{
		draw_square(dst, create_roi(img_coord.x, img_coord.y, 1,
					case_size.y * rack_size.y + 1), pixel);
		img_coord.x += case_size.x;
		++rack_coord.x;
	}
}
