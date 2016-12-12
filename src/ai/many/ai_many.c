
#include "filler.h"
#include "ai_many.h"

static	int		is_player_in_rob(t_params *params, t_roi rob)
{
	t_coord crd;

	if (rob.x + rob.width > params->board_size.x)
		rob.width = params->board_size.x - rob.x;
	if (rob.y + rob.height > params->board_size.y)
		rob.height = params->board_size.y - rob.y;
	crd.y = 0;
	while (crd.y < rob.height)
	{
		crd.x = 0;
		while (crd.x < rob.width)
		{
			if (params->game_board[crd.y + rob.y][crd.x + rob.x]\
				== params->player[0]|| \
				params->game_board[crd.y + rob.y][crd.x + rob.x]\
				== params->player[1])
				return (1);
			++crd.x;
		}
		++crd.y;
	}
	return (0);
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


static t_list			*list_possible_position(t_params *params)
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

static	void	del_lst(void *content, size_t size)
{
	(void)size;
	if (content)
		ft_memdel(&content);
}

int				ai_launch(t_params *params, t_coord *to_play)
{
	t_list	*lst;

	lst = list_possible_position(params);
	list_sort_by_weight(lst);
	if (lst)
		*to_play = ((t_pos *)lst->content)->coord;
	ft_lstdel(&lst, del_lst);
	return(1);
}