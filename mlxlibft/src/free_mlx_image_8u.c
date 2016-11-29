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
#include <stdlib.h>
#include <mlx.h>

void	free_mlx_image_8u(void *mlx_ptr, t_mlx_image_8u *image)
{
	if (image)
	{
		mlx_destroy_image(mlx_ptr, image->ptr);
		free(image);
	}
}
