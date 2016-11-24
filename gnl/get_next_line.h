/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:52:11 by mlegendr          #+#    #+#             */
/*   Updated: 2014/12/08 16:59:52 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFF_SIZE
#  define BUFF_SIZE 210
# endif

# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include "libft.h"
# include <fcntl.h>

typedef struct		s_read
{
	int				fd;
	char			*read;
	char			*read_cpy;
	struct s_read	*next;
}					t_read;

int					get_next_line(int const fd, char **line);

#endif
