/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 21:05:32 by mlegendr          #+#    #+#             */
/*   Updated: 2014/12/22 21:19:45 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!(new = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	while (n > i)
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
