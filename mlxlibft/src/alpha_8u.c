/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_8u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:54:21 by mlegendr          #+#    #+#             */
/*   Updated: 2016/11/28 17:46:36 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxlibft.h"

void	alpha_8u(t_mlx_image_8u *image, int x, int y, t_sample_8u alpha)
{
	const int pos = image->width * y + x;

	*(((t_sample_8u *)&((((int *)image->data)[pos]))) + 3) = alpha;
}
