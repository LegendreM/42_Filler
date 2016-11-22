/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 20:00:16 by mlegendr          #+#    #+#             */
/*   Updated: 2014/11/05 10:25:24 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	while (s[i] && s[i] != (char)c)
		++i;
	if (s[i] == (char)c)
		str = (char*)&s[i];
	return (str);
}
