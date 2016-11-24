/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_8u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:55:14 by mlegendr          #+#    #+#             */
/*   Updated: 2016/03/21 15:55:19 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxlibft.h"

void	pixel_8u(t_mlx_image_8u *image, int x, int y, t_pixel_8u pixel)
{
	const int pos = image->width * y + x;

	*(((t_sample_8u *)&((((int *)image->data)[pos])))) = pixel.blue;
	*(((t_sample_8u *)&((((int *)image->data)[pos]))) + 1) = pixel.green;
	*(((t_sample_8u *)&((((int *)image->data)[pos]))) + 2) = pixel.red;
	*(((t_sample_8u *)&((((int *)image->data)[pos]))) + 3) = pixel.alpha;
}
