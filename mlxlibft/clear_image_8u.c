/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image_8u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:52:11 by mlegendr          #+#    #+#             */
/*   Updated: 2014/12/08 16:59:52 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxlibft.h"

int	clear_image_8u(t_mlx_image_8u *image, const t_pixel_8u pixel)
{
	int			i;
	t_color_8u	*data;
	t_color_8u	*color;

	color = (t_color_8u*)&pixel;
	data = (t_color_8u*)image->data;
	i = 0;
	while (i < image->width * image->height)
	{
		data[i] = *color;
		++i;
	}
	return (0);
}
