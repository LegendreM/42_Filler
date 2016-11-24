#include <sys/types.h>//read
#include <sys/uio.h>//read
#include <unistd.h>//read
#include <fcntl.h>//open
#include <stdio.h>//printf
#include "libft.h"
#include "get_next_line.h"
#include "Filler.h"



int	strstart(char *str, char *start)
{
	int i;

	i = 0;
	while(str[i] && start[i])
	{
		if (start[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

//piece coord
void	ft_play()
{
	write(1, "8 2\n", 4);
	return ;
}

//map recuparation
void	ft_get_map()
{
	return ;
}

void	ft_mystrjoin(char **s1, const char *s2)
{
	int		s1_size;
	int		s2_size;
	char*	all;
	int		i;

	i = 0;
	s1_size = 0;
	s2_size = 0;	
	if(*s1)
		s1_size = ft_strlen(*s1);
	if(s2)
		s2_size = ft_strlen(s2);	
	all = ft_strnew(s1_size + s2_size);
	all = ft_strcat(*s1, s2);
	ft_strdel(s1);
	*s1 = ft_strdup(all);
	ft_strdel(&all);
}

//read
void	ft_read(char **all)
{
	char*	line;
	int		ret;
	int 	fd;

	fd = 0;
	ret = 0;
	line = NULL;
	fd = open("./toto.log", O_RDWR);
	while(get_next_line(0, &line) > 0)
	{
		ft_mystrjoin(all, line);
		if (strstart(line, "Plateau "))
		{
			ft_get_map();
		}
	}
	return ;
}

// t_params	*ft_params_init(board_width, board_height)
// {
// 	(void)board_height;
// 	(void)board_width;

// }

int	main(void)
{
	int fd;
	char* all;
	// t_params*	params;

	// params = ft_params_init();
	fd = 0;
	fd = open("./toto.log", O_RDWR);
	ft_read(&all);
	ft_putstr_fd(all, fd);
	ft_putstr_fd(all, 2);
	ft_play();
	return (0);
}
