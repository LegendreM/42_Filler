/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:11:04 by mlegendr          #+#    #+#             */
/*   Updated: 2014/11/07 13:41:32 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(s2);
	if (s2 == NULL || s2[0] == '\0')
		return ((char*)s1);
	while (s1[i])
	{
		while (s2[j] == s1[i + j])
		{
			j++;
			if (j == len)
			{
				return ((char*)&s1[i]);
			}
		}
		j = 0;
		++i;
	}
	return (NULL);
}
