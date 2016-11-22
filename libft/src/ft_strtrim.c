/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:00:55 by mlegendr          #+#    #+#             */
/*   Updated: 2014/11/09 15:17:35 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	size_t			end;
	size_t			len;
	char			*newstr;

	start = 0;
	end = 0;
	len = 0;
	newstr = NULL;
	if (s)
	{
		end = ft_strlen(s);
		while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			++start;
		while (s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t')
			--end;
		if (end < (size_t)start)
			end = start;
		len = end - (size_t)start;
		newstr = ft_strsub(s, start, len);
	}
	return (newstr);
}
