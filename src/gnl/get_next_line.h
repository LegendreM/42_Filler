/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmejia <dmejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 09:55:48 by dmejia            #+#    #+#             */
/*   Updated: 2015/01/05 13:13:45 by dmejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 8

typedef	struct	s_tools
{
	int			fd;
	char		*stock;
}				t_tools;
int				get_next_line(int const fd, char **line);

#endif
