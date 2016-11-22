/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:29:26 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:29:29 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"

static long long int		ft_llintlen(long long int n)
{
	unsigned long long int	len;

	len = 0;
	if (n < 0)
		++len;
	while (n != 0)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char						*ft_llitoa(long long int n)
{
	char					*strnew;
	unsigned long long int	len;

	if (n == 0)
	{
		if (!(strnew = ft_strnew(1)))
			return (NULL);
		strnew[0] = '0';
		return (strnew);
	}
	len = ft_llintlen(n);
	if (!(strnew = ft_strnew(len)))
		return (NULL);
	len -= 1;
	if (n > 0)
		n *= -1;
	if (n < 0)
		strnew[0] = '-';
	while (n < 0)
	{
		strnew[len] = -(n % 10) + 48;
		n /= 10;
		--len;
	}
	return (strnew);
}
