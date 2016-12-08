
#include "filler.h"
#include "ai_many.h"

t_list			*list_possible_position(t_params params)
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

int				ft_lstlen(t_list lst)
{
	return ((lst == NULL) ? 0 : ft_lstlen(lst->next) + 1);
}

void			ft_lstswap(t_list *current, t_list *next)
{
	current->content ^= next->content;
	next->content ^= current->content;
	current->content ^= next->content;

}

void			swap_by_weight(t_list *lst)
{
	const t_pos *c = (t_pos *)lst->content;
	const t_pos *nc = (t_pos *)lst->next->content;

	if (c->p_weight > nc->p_weight)
		return ;
	else if (c->p_weight < nc->p_weight)
	{

	}
}

void			list_sort_by_weight(t_list *lst)
{
	int len;

	if (!lst)
		return ;
	len = ft_lstlen(lst);
	while (--len > -1)
		ft_lstiter(lst)

}

