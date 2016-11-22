/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:33:08 by mlegendr          #+#    #+#             */
/*   Updated: 2014/11/03 17:25:43 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char		*temp_src;
	char			*temp_dst;

	temp_dst = dst;
	temp_src = src;
	if (dst <= src)
	{
		return (ft_memcpy(dst, src, len));
	}
	temp_dst = temp_dst + len;
	temp_src = temp_src + len;
	while (len--)
		*--temp_dst = *--temp_src;
	return (dst);
}
