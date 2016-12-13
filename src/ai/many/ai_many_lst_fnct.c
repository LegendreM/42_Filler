/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_many_lst_fnct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:11:52 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/12 17:26:49 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "ai_many.h"

int				ft_lstlen(t_list *lst)
{
	return ((lst == NULL) ? 0 : ft_lstlen(lst->next) + 1);
}

void			ft_lstswap(t_list *current, t_list *next)
{
	void *tmp;

	tmp = next->content;
	next->content = current->content;
	current->content = tmp;
}

void			swap_by_weight(t_list *lst)
{
	t_pos *c;
	t_pos *nc;

	if (!lst->next)
		return ;
	c = (t_pos *)lst->content;
	nc = (t_pos *)lst->next->content;
	if (c->p_weight > nc->p_weight)
	{
		return ;
	}
	if (c->p_weight < nc->p_weight || c->s_weight < nc->s_weight)
	{
		return (ft_lstswap(lst, lst->next));
	}
}

void			list_sort_by_weight(t_list *lst)
{
	int len;

	if (!lst)
		return ;
	len = ft_lstlen(lst);
	while (--len > -1)
		ft_lstiter(lst, swap_by_weight);
}

void			del_lst(void *content, size_t size)
{
	(void)size;
	if (content)
		ft_memdel(&content);
}
