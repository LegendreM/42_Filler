/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:45:42 by mlegendr          #+#    #+#             */
/*   Updated: 2014/11/15 11:43:17 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dst;

	j = 0;
	if (s)
	{
		i = len;
		dst = (char *)malloc(sizeof(*dst) * (len + 1));
		if (dst == NULL)
			return (NULL);
		while (i != 0)
		{
			dst[j] = s[start];
			start++;
			i--;
			j++;
		}
		dst[j] = '\0';
		return (dst);
	}
	return (NULL);
}
