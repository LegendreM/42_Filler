/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_disk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:54:59 by mlegendr          #+#    #+#             */
/*   Updated: 2016/03/21 15:55:02 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxlibft.h"

void	draw_x_line(t_mlx_image_8u *dst,
				const t_coord begin,
				const int size,
				const t_pixel_8u pixel)
{
	int					i;
	t_color_8u			*data;
	const int			end = begin.y * dst->width + begin.x + size;
	const t_color_8u	color = pixel_to_color_8u(pixel);

	i = begin.y * dst->width + begin.x;
	data = (t_color_8u*)dst->data;
	while (i < end)
	{
		data[i] = color;
		++i;
	}
}

void	draw_disk(t_mlx_image_8u *dst,
				const t_coord center,
				const int radius,
				const t_pixel_8u pixel)
{
	int 	x;
	int 	y;
	int 	err;

	x = radius;
	y = 0;
	err = 0;
	while (x >= y)
	{
		draw_x_line(dst, (t_coord){.x = center.x - x, .y = center.y + y},
					2 * x, pixel);
		draw_x_line(dst, (t_coord){.x = center.x - x, .y = center.y - y},
					2 * x, pixel);
		y += 1;
		err += 1 + 2 * y;
		if (2 * (err - x) + 1 > 0)
		{
			draw_x_line(dst, (t_coord){.x = center.x - (y - 1),
										.y = center.y + x}, 2 * (y - 1), pixel);
			draw_x_line(dst, (t_coord){.x = center.x - (y - 1),
										.y = center.y - x}, 2 * (y - 1), pixel);
			x -= 1;
			err += 1 - 2 * x;
		}
	}
}

void	draw_disk_in_roi(t_mlx_image_8u *dst,
						const t_roi roi,
						const t_pixel_8u pixel)
{
	t_coord	coord;
	int		radius;

	coord.x = roi.x + roi.width / 2;
	coord.y = roi.y + roi.height / 2;
	radius = (roi.width < roi.height) ? roi.width / 2 : roi.height / 2;
	draw_disk(dst, coord, radius, pixel);
}
