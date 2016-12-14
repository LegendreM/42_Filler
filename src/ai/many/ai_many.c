/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_many.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:11:52 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/12 17:26:49 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "ai_many.h"

static	void	ajust_rob(t_params *params, t_roi *rob)
{
	if (rob->x + rob->width > params->board_size.x)
		rob->width = params->board_size.x - rob->x;
	if (rob->y + rob->height > params->board_size.y)
		rob->height = params->board_size.y - rob->y;
}

static	int		is_player_in_rob(t_params *params, t_roi rob)
{
	t_coord crd;
	int		weight[2];

	ajust_rob(params, &rob);
	crd.y = -1;
	weight[0] = 0;
	weight[1] = 0;
	while (++crd.y < rob.height)
	{
		crd.x = -1;
		while (++crd.x < rob.width)
			if (params->game_board[crd.y + rob.y][crd.x + rob.x] != '.')
			{
				if (params->game_board[crd.y + rob.y][crd.x + rob.x]\
					== params->player[0] || \
					params->game_board[crd.y + rob.y][crd.x + rob.x]\
					== params->player[1])
					weight[0] = 1;
				else
					weight[1] = 1;
			}
	}
	return ((weight[0] > 0) ? weight[0] + weight[1] : 0);
}

static	int		get_area(t_params *params, int rob_size)
{
	int		weight;
	t_roi	rob;

	rob = (t_roi){.x = 0, .y = 0, .width = rob_size, .height = rob_size};
	weight = 0;
	while (rob.y < params->board_size.y)
	{
		rob.x = 0;
		while (rob.x < params->board_size.x)
		{
			weight += is_player_in_rob(params, rob);
			rob.x += rob.width;
		}
		rob.y += rob.height;
	}
	return (weight);
}

static t_list	*list_possible_position(t_params *params)
{
	t_coord		pos[params->board_size.x * params->board_size.y];
	int			pos_size;
	t_list		*list;
	t_pos		tmp;

	list = NULL;
	pos_size = get_possible_positions(params, pos);
	while (--pos_size > -1)
	{
		place_piece(params, pos[pos_size]);
		tmp.coord = pos[pos_size];
		tmp.p_weight = get_area(params, 4);
		tmp.s_weight = get_area(params, 2);
		ft_lstadd(&list, ft_lstnew((void *)&tmp, sizeof(tmp)));
		reset_piece(params, pos[pos_size]);
	}
	return (list);
}

int				ai_launch(t_params *params, t_coord *to_play)
{
	t_list	*lst;

	lst = list_possible_position(params);
	list_sort_by_weight(lst);
	if (lst)
		*to_play = ((t_pos *)lst->content)->coord;
	ft_lstdel(&lst, del_lst);
	return (1);
}
