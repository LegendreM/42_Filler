/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pixel_8u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:54:42 by mlegendr          #+#    #+#             */
/*   Updated: 2016/03/21 15:54:47 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxlibft.h"

inline	t_pixel_8u	create_pixel_8u(t_sample_8u red, t_sample_8u green,
							t_sample_8u blue, t_sample_8u alpha)
{
	return (
		(t_pixel_8u){.alpha = alpha, .red = red, .green = green, .blue = blue});
}
