/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:19:25 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/02 17:28:16 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		set_piece_size(char *line, t_params *params)
{
	int		i;

	i = 0;
	while (ft_isalpha(line[i]) || line[i] == ' ')
		++i;
	params->piece_size.y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		++i;
	params->piece_size.x = ft_atoi(&line[i]);
	params->game_piece = ft_matrixnew(
							params->piece_size.y,
							params->piece_size.x);
	return ;
}

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

static void		ft_get_piece_min(char **piece, const t_coord size,
				t_params *params)
{
	int		y;

	y = 0;
	if (params->game_piece_min != NULL)
		free(params->game_piece_min);
	params->piece_orig = find_piece_min_origin(piece, size);
	params->piece_size_min = find_piece_min_size(piece, size,
								(const t_coord)params->piece_orig);
	params->game_piece_min =
		(char **)malloc(sizeof(params->piece_size_min.y));
	while (y < params->piece_size_min.y)
	{
		params->game_piece_min[y] = piece[y - params->piece_orig.y]
										- params->piece_orig.x;
		y++;
	}
	return ;
}

void			ft_get_piece(char *line, t_params *params)
{
	int		i;

	if (params->game_piece != NULL)
		ft_matrixdel(params->game_piece);
	set_piece_size(line, params);
	i = 0;
	while (i < params->piece_size.y)
	{
		get_next_line(FD, &line);
		ft_strncpy(
			params->game_piece[i],
			line,
			params->piece_size.x);
		i++;
	}
	ft_get_piece_min(params->game_piece,
			(const t_coord)params->piece_size,
			params);
	return ;
}
