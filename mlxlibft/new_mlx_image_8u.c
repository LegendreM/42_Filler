/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_mlx_image_8u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:53:11 by mlegendr          #+#    #+#             */
/*   Updated: 2016/03/21 15:53:17 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxlibft.h"
#include <stdlib.h>
#include <mlx.h>

t_mlx_image_8u	*new_mlx_image_8u(void *mlx_ptr, int width, int height)
{
	t_mlx_image_8u	*image;
	int				bpp;
	int				sl;
	int				endian;

	if (!(image = (t_mlx_image_8u *)malloc(sizeof(t_mlx_image_8u))))
		return (NULL);
	if (!(image->ptr = mlx_new_image(mlx_ptr, width, height)))
		return (NULL);
	if (!(image->data =
			(t_sample_8u *)mlx_get_data_addr(image->ptr, &bpp, &sl, &endian)))
		return (NULL);
	if (bpp != 32 || endian != 0)
		return (NULL);
	image->width = width;
	image->height = height;
	return (image);
}
