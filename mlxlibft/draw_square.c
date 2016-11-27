/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:55:14 by mlegendr          #+#    #+#             */
/*   Updated: 2016/03/21 15:55:19 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxlibft.h"

int	draw_square(t_mlx_image_8u *dst, const t_roi square, const t_pixel_8u color)
{
	const int	max_x = square.x + square.width;
	const int	max_y = square.y + square.height;
	int			y;
	int			x;

	if (square.x < 0 || max_x > dst.width)
		return (1);
	if (square.y < 0 || max_y > dst.height)
		return (1);
	y = square.y;
	while (y < max_y)
	{
		x = square.x;
		while (x < max_x)
		{
			pixel_8u(dst, x, y, color);
			++x;
		}
		++y;
	}
	return (0);
}
