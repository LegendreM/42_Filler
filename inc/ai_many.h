/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_many.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 09:14:11 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/13 09:22:23 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AI_MANY_H

# define AI_MANY_H

typedef struct	s_pos
{
	t_coord		coord;
	int			p_weight;
	int			s_weight;
}				t_pos;

void			list_sort_by_weight(t_list *lst);
void			del_lst(void *content, size_t size);
#endif
