/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:54:59 by mlegendr          #+#    #+#             */
/*   Updated: 2016/11/30 10:17:37 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxlibft.h"

void	draw_circle(t_mlx_image_8u *dst,
				const t_coord coord,
				const int radius,
				const t_pixel_8u pixel)
{
	int x;
	int y;
	int err;

	x = radius;
	y = 0;
	err = 0;
	while (x >= y)
	{
		pixel_8u(dst, coord.x + x, coord.y + y, pixel);
		pixel_8u(dst, coord.x + y, coord.y + x, pixel);
		pixel_8u(dst, coord.x - y, coord.y + x, pixel);
		pixel_8u(dst, coord.x - x, coord.y + y, pixel);
		pixel_8u(dst, coord.x - x, coord.y - y, pixel);
		pixel_8u(dst, coord.x - y, coord.y - x, pixel);
		pixel_8u(dst, coord.x + y, coord.y - x, pixel);
		pixel_8u(dst, coord.x + x, coord.y - y, pixel);
		y += 1;
		err += 1 + 2 * y;
		if (2 * (err - x) + 1 > 0)
		{
			x -= 1;
			err += 1 - 2 * x;
		}
	}
}

void	draw_circle_in_roi(t_mlx_image_8u *dst,
			const t_roi roi,
			const t_pixel_8u pixel)
{
	t_coord	coord;
	int		radius;

	coord.x = roi.x + roi.width / 2;
	coord.y = roi.y + roi.height / 2;
	radius = (roi.width < roi.height) ? roi.width / 2 : roi.height / 2;
	draw_circle(dst, coord, radius, pixel);
}
