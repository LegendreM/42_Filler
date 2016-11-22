/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 09:10:17 by mlegendr          #+#    #+#             */
/*   Updated: 2014/11/09 11:24:34 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*ptr;
	void	*s;

	i = 0;
	s = NULL;
	if (!(ptr = (char*)malloc(sizeof(*ptr) * size)))
		return (NULL);
	if (ptr)
	{
		while (i < size)
		{
			ptr[i] = 0;
			++i;
		}
		s = ptr;
	}
	return (s);
}
