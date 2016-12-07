/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:15:13 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/07 14:15:17 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_coord	find_piece_min_origin(char **piece, const t_coord size)
{
	t_coord	orig;
	int		x;
	int		y;

	orig.x = 1;
	orig.y = 1;
	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			if (piece[y][x] == '*')
			{
				if (-x > orig.x || orig.x == 1)
					orig.x = -x;
				if (-y > orig.y || orig.y == 1)
					orig.y = -y;
			}
			x++;
		}
		y++;
	}
	return (orig);
}

static t_coord	find_piece_min_size(char **piece, const t_coord size,
			const t_coord orig)
{
	int		x;
	int		y;
	t_coord	size_min;

	size_min.x = 0;
	size_min.y = 0;
	y = -orig.y;
	while (y < size.y)
	{
		x = -orig.x;
		while (x < size.x)
		{
			if (piece[y][x] == '*')
			{
				if (y + 1 + orig.y > size_min.y)
					size_min.y = y + 1 + orig.y;
				if (x + 1 + orig.x > size_min.x)
					size_min.x = x + 1 + orig.x;
			}
			x++;
		}
		y++;
	}
	return (size_min);
}

static void		set_piece_min(t_params *params)
{
	int		y;

	if (params->game_piece_min != NULL)
		ft_matrixdel(params->game_piece_min);
	params->piece_orig = find_piece_min_origin(params->game_piece,
							params->piece_size);
	params->piece_size_min = find_piece_min_size(params->game_piece,
								params->piece_size,
								(const t_coord)params->piece_orig);
	params->game_piece_min = ft_matrixnew(params->piece_size_min.y,
								params->piece_size_min.x);
	y = 0;
	while (y < params->piece_size_min.y)
	{
		ft_strncpy(
				params->game_piece_min[y],
				params->game_piece[y - params->piece_orig.y]
					- params->piece_orig.x,
				params->piece_size_min.x);
		++y;
	}
	return ;
}

static void		set_piece_size(char *line, t_params *params)
{
	int		i;

	i = 0;
	while (ft_isalpha(line[i]))
		++i;
	++i;
	params->piece_size.y = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		++i;
	params->piece_size.x = ft_atoi(line + i);
	params->game_piece = ft_matrixnew(params->piece_size.y,
							params->piece_size.x);
	return ;
}

void			set_piece(char *line, t_params *params)
{
	int		y;

	if (params->game_piece != NULL)
		ft_matrixdel(params->game_piece);
	set_piece_size(line, params);
	y = params->piece_size.y;
	while (y > 0)
	{
		get_next_line(FD, &line);
		ft_strncpy(
				params->game_piece[params->piece_size.y - y],
				line,
				params->piece_size.x);
		free(line);
		--y;
	}
	set_piece_min(params);
	return ;
}
