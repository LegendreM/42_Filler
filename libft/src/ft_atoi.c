/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:34:25 by mlegendr          #+#    #+#             */
/*   Updated: 2014/11/07 19:46:11 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int signe;
	int nb;

	i = 0;
	signe = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' \
	|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		++i;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb *= 10;
		nb += str[i] - 48;
		++i;
	}
	if (signe == -1)
		nb *= -1;
	return (nb);
}
