/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 20:32:19 by mlegendr          #+#    #+#             */
/*   Updated: 2014/11/09 22:02:30 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*first;
	t_list	*add;

	if (!f || !lst)
		return (NULL);
	new = (*f)(lst);
	if (!(new = ft_lstnew(new->content, new->content_size)))
		return (NULL);
	lst = lst->next;
	first = new;
	while (lst)
	{
		add = (*f)(lst);
		if (!(add = ft_lstnew(add->content, add->content_size)))
			return (NULL);
		new->next = add;
		new = new->next;
		lst = lst->next;
	}
	return (first);
}
