/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx_image_8u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:54:42 by mlegendr          #+#    #+#             */
/*   Updated: 2016/06/02 15:44:18 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxlibft.h"

t_pixel_8u	get_pixel_8u(t_mlx_image_8u *image, int x, int y)
{
	t_sample_8u		a;
	t_sample_8u		r;
	t_sample_8u		g;
	t_sample_8u		b;
	const int		pos = image->width * y + x;

	b = *(((t_sample_8u *)&((((int *)image->data)[pos]))));
	g = *(((t_sample_8u *)&((((int *)image->data)[pos]))) + 1);
	r = *(((t_sample_8u *)&((((int *)image->data)[pos]))) + 2);
	a = *(((t_sample_8u *)&((((int *)image->data)[pos]))) + 3);
	return (create_pixel_8u(r, g, b, a));
}
