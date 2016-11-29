/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_8u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:53:27 by mlegendr          #+#    #+#             */
/*   Updated: 2016/03/21 15:53:35 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxlibft.h"

void	red_8u(t_mlx_image_8u *image, int x, int y, t_sample_8u red)
{
	const int pos = image->width * y + x;

	*(((t_sample_8u *)&((((int *)image->data)[pos]))) + 2) = red;
}
