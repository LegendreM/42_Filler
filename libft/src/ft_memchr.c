/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:15:20 by mlegendr          #+#    #+#             */
/*   Updated: 2014/11/07 13:05:39 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	void				*ret;

	str = s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
		{
			ret = (void*)&str[i];
			return (ret);
		}
		++i;
	}
	return (NULL);
}
