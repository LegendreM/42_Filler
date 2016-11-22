/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:26:14 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:26:19 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_letter(char *format, int nbc)
{
	int len;
	int	i;

	i = 0;
	len = ((int)ft_strlen(format)) - 1;
	while (nbc != 0)
	{
		if (i == 0 && ft_findflag("sSpdDioOuUxXcCb", format[len]) == -1)
		{
			ft_error(kSyntax, __FUNCTION__, __LINE__);
		}
		if (i == 1 && ((ft_findflag("lzjh", format[len - i]) == -1) \
			|| (ft_findflag("diouxXscb", format[len]) == -1)))
		{
			ft_error(kSyntax, __FUNCTION__, __LINE__);
		}
		if (i == 2 && ((ft_findflag("lzjh", format[len - i]) == -1) \
			|| (ft_findflag("diouxXb", format[len]) == -1)))
		{
			ft_error(kSyntax, __FUNCTION__, __LINE__);
		}
		++i;
		--nbc;
	}
	return ;
}

int		ft_check_points(char *format)
{
	int	i;
	int	count;
	int len;

	len = ((int)ft_strlen(format)) - 1;
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '.')
			++count;
		++i;
	}
	if (ft_findflag("dDioOuUxXbs%", format[len]) == -1 && count > 0)
	{
		ft_error(kSyntax, __FUNCTION__, __LINE__);
	}
	return (count);
}

int		ft_check_sharp(char *format)
{
	int	i;
	int count;
	int len;

	len = ((int)ft_strlen(format)) - 1;
	count = 0;
	i = 1;
	while (format[i])
	{
		if (format[i] == '#')
			++count;
		if (i > 1 && ft_findflag("#", format[i]) != -1 &&
			ft_findflag("-#0$", format[i - 1]) == -1)
			ft_error(kSyntax, __FUNCTION__, __LINE__);
		++i;
	}
	if (count > 0 && ft_findflag("xoXO", format[len]) == -1)
		ft_error(kSyntax, __FUNCTION__, __LINE__);
	return (count);
}

int		ft_check_zero(t_format *format)
{
	int i;
	int len;

	len = ((int)ft_strlen(format->format)) - 1;
	i = 1;
	if (format->dollar > 0)
		while (format->format[i++] != '$')
			;
	while (format->format[i] && format->format[i] != '-' &&
		(!ft_isalnum(format->format[i]) || format->format[i] == '0'))
	{
		if (format->format[i] == '0')
		{
			if (ft_findflag("SsCcp", format->format[len]) != -1)
				ft_error(kSyntax, __FUNCTION__, __LINE__);
			return (1);
		}
		++i;
	}
	return (0);
}
