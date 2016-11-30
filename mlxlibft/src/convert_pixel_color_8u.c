/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pixel_color_8u.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:54:59 by mlegendr          #+#    #+#             */
/*   Updated: 2016/03/21 15:55:02 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxlibft.h"

inline t_color_8u	pixel_to_color_8u(const t_pixel_8u pixel)
{
	t_color_8u	*color;

	color = (t_color_8u*)&pixel;
	return (*color);
}

inline t_pixel_8u	color_to_pixel_8u(const t_color_8u color)
{
	t_pixel_8u	*pixel;

	pixel = (t_pixel_8u*)&color;
	return (*pixel);
}
