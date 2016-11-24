/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx_image_8u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:54:42 by mlegendr          #+#    #+#             */
/*   Updated: 2016/03/21 15:54:47 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxlibft.h"

t_pixel_8u	new_pixel_8u(t_sample_8u red, t_sample_8u green, t_sample_8u blue,
						t_sample_8u alpha)
{
	t_pixel_8u	pixel;

	pixel.red = red;
	pixel.green = green;
	pixel.blue = blue;
	pixel.alpha = alpha;
	return (pixel);
}
