/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:42:34 by mlegendr          #+#    #+#             */
/*   Updated: 2015/01/02 17:05:40 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static size_t		countw(char const *s, char c)
{
	size_t		i;
	size_t		len;

	i = 1;
	len = 0;
	while (s[i] != '\0')
	{
		if ((s[i - 1] != c && s[i] == c) || (i == 0 && s[i] != c) \
			|| (i == ft_strlen(s) - 1 && s[i] != c))
			len++;
		i++;
	}
	return (len);
}

static void			cutcut(char const *s, char c, char **ret)
{
	size_t		i;
	size_t		j;
	size_t		start;
	size_t		end;

	i = 0;
	j = 0;
	start = 0;
	end = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		if (end != start)
		{
			ret[j] = ft_strsub(s, (unsigned int)start, end - start);
			j++;
		}
	}
}

char				**ft_strsplit(char const *s, char c)
{
	size_t		len;
	char		**ret;

	len = 0;
	if (!s)
		return (NULL);
	len = countw(s, c);
	ret = (char**)malloc(sizeof(char*) * (len + 1));
	if (ret == NULL)
		return (NULL);
	ret[len] = 0;
	if (ft_strequ(s, ""))
		ret[0] = NULL;
	else
		cutcut(s, c, ret);
	return (ret);
}
