/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:21:13 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/19 09:08:17 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	set_player(char *line, t_params *params)
{
	if (ft_strstr((const char*)line, "$$$ exec p1 :"))
	{
		params->player[0] = 'O';
		params->player[1] = 'o';
	}
	else if (ft_strstr((const char*)line, "$$$ exec p2 :"))
	{
		params->player[0] = 'X';
		params->player[1] = 'x';
	}
	return ;
}

static void	set_board_size(char *line, t_params *params)
{
	int		i;

	i = 0;
	while (ft_isalpha(line[i]))
		++i;
	++i;
	params->board_size.y = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		++i;
	params->board_size.x = ft_atoi(line + i);
	params->game_board = ft_matrixnew(params->board_size.y,
							params->board_size.x);
	return ;
}

static void	set_board(char *line, t_params *params)
{
	int		y;

	if (params->game_board == NULL)
		set_board_size(line, params);
	y = params->board_size.y;
	get_next_line(FD, &line);
	free(line);
	while (y > 0)
	{
		get_next_line(FD, &line);
		ft_strncpy(
				params->game_board[params->board_size.y - y],
				line + 4,
				params->board_size.x);
		free(line);
		--y;
	}
	return ;
}

static int	check_input(char *line, t_params *params)
{
	int		i;

	i = 0;
	if (line != NULL)
	{
		if (params->player[0] == '\0'
				&& ft_strstr((const char *)line, "$$$ exec") != NULL)
			set_player(line, params);
		else if (params->player[0] == '\0')
			return (0);
		else if (ft_strstr((const char *)line, "Plateau"))
			set_board(line, params);
		else if (ft_strstr((const char *)line, "Piece"))
		{
			set_piece(line, params);
			return (0);
		}
	}
	return (1);
}

t_params	*parser(t_params *params)
{
	char		*line;

	while (get_next_line(FD, &line))
	{
		if (check_input(line, params) == 0)
			break ;
		free(line);
	}
	free(line);
	return (params);
}
