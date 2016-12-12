/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_closer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:20:02 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/12 15:57:03 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ai_wyki.h"

static int	ft_sqrt(int nb)
{
	int i;
	int sq;

	i = 1;
	sq = 1;
	if (nb == 0)
		return (0);
	while (i * i < nb)
	{
		i++;
	}
	if ((nb % i) == 0)
		return (i);
	else
		return (i - 1);
}

static int	get_distance(t_coord a, t_coord b)
{
	int		dist;
	int		x_dist;
	int		y_dist;

	x_dist = a.x - b.x;
	y_dist = a.y - b.y;
	x_dist = x_dist < 0 ? -x_dist : x_dist;
	y_dist = y_dist < 0 ? -y_dist : y_dist;
	dist = x_dist * x_dist + y_dist * y_dist;
	dist = ft_sqrt(dist);
	return (dist);
}

static int	count_ennemy(t_params *params, t_coord pos)
{
	int		ret;
	char	op_c;

	op_c = params->player[0] == 'O' ? 'X' : 'O';
	ret = 0;
	if (pos.x - 1 > 0 && params->game_board[pos.y][pos.x - 1] == op_c)
		++ret;
	if (pos.x + 1 < params->board_size.x
			&& params->game_board[pos.y][pos.x + 1] == op_c)
		++ret;
	if (pos.y - 1 > 0 && params->game_board[pos.y - 1][pos.x] == op_c)
		++ret;
	if (pos.y + 1 < params->board_size.y
			&& params->game_board[pos.y + 1][pos.x] == op_c)
		++ret;
	return (ret);
}

static int	touch_ennemy(t_params *params, t_coord pos)
{
	int		ret;
	int		x;
	int		y;

	y = 0;
	ret = 0;
	while (y < params->piece_size_min.y)
	{
		x = 0;
		while (x < params->piece_size_min.x)
		{
			if (params->game_piece_min[y][x] == '*')
				ret += count_ennemy(params, (t_coord){.x = x + pos.x,
						.y = y + pos.y});
			++x;
		}
		++y;
	}
	return (ret);
}

t_coord		go_closer(t_params *params, t_coord *pos, int pos_size,
				t_square *op)
{
	int		x;
	int		touched_ennemies;
	int		tmp;
	t_coord	ret;

	x = 0;
	touched_ennemies = 0;
	ret = pos_size > 0 ? pos[0] : (t_coord){0, 0};
	while (x < pos_size)
	{
		if (get_distance(pos[x], op->center) <= get_distance(ret, op->center)
			&& (tmp = touch_ennemy(params, pos[x])) > touched_ennemies)
		{
			ret = pos[x];
			touched_ennemies = tmp;
		}
		++x;
	}
	return (ret);
}
