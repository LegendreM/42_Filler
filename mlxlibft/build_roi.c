/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_roi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:55:14 by mlegendr          #+#    #+#             */
/*   Updated: 2016/03/21 15:55:19 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxlibft.h"

t_roi	build_roi(int x, int y, int width, int height)
{
	t_roi roi;

	roi.x = x;
	roi.y = y;
	roi.width = width;
	roi.height = height;
	return (roi);
}
