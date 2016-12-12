/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:02:28 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/12 17:11:33 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	my_sqrt(int nb)
{
	int i;

	i = 0;
	while ((i * i) < nb)
		++i;
	return (i);
}

int			get_dist(t_coord start_point, t_coord end_point)
{
	int dist;

	dist = my_sqrt((start_point.x - end_point.x)
				* (start_point.x - end_point.x)
			+ (start_point.y - end_point.y)
				* (start_point.y - end_point.y));
	return (dist);
}
