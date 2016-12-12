/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_edge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:45:58 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/12 17:10:09 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ai_wyki.h"

static int	ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

static int	ft_max(int n1, int n2)
{
	return (n1 > n2 ? n1 : n2);
}

int			check_edge(t_params *params, char c, t_coord orig, t_coord end)
{
	int		x_cnt;
	int		y_cnt;

	x_cnt = ft_max(orig.x, end.x) != 0
				? ft_abs(orig.x - end.x) / ft_max(orig.x, end.x)
				: 0;
	y_cnt = ft_max(orig.y, end.y) != 0
				? ft_abs(orig.y - end.y) / ft_max(orig.y, end.y)
				: 0;
	while (orig.y <= end.y && orig.x <= end.x)
	{
		if (params->game_board[orig.y][orig.x] == c)
			return (1);
		orig.x += x_cnt;
		orig.y += y_cnt;
	}
	return (0);
}
