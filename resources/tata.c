#define BUFFSIZE 8
#define FD 0
#define PLAYER_NAME "[players/tata.filler]"

#include <sys/types.h>//read
#include <sys/uio.h>//read
#include <unistd.h>//read
#include "libft.h"
#include "get_next_line.h"
#include "Filler.h"

char	*ft_mystrjoin_and_free(char *s1, char *s2)
{
	size_t			lens1;
	size_t			lens2;
	char			*newstr;

	lens1 = 0;
	lens2 = 0;
	if (s1 && s2)
	{
		lens1 = ft_strlen(s1);
		lens2 = ft_strlen(s2);
		newstr = ft_strnew(lens1 + lens2);
		if (newstr)
		{
			newstr = ft_strcat(newstr, s1);
			newstr = ft_strcat(newstr, s2);
			ft_strdel(&s1);
			return (newstr);
		}
	}
	return (NULL);
}

void	ft_board_size(char *start, int board_coord[2])
{
	int i;

	i = 0;

	while(ft_isalpha(start[i]))
		++i;
	++i;
	board_coord[0] = ft_atoi(&start[i]);
	while(ft_isdigit(start[i]))
		++i;
	board_coord[1] = ft_atoi(&start[i]);
	return ;
}

int	ft_player_number(char *start)
{
	return(ft_atoi(&start[-4]));
}

void	ft_play(int x, int y)
{
	char* x_str;
	char* y_str;

	if((x_str = ft_itoa(x)) && (y_str = ft_itoa(y)))
	{
		write(1, x_str, ft_strlen(x_str));
		write(1, " ", 1);
		write(1, y_str, ft_strlen(y_str));
		write(1, "\n", 1);
	}
	return ;
}

void	ft_check_plateau(char *str, char *map)
{
	int i;
	int board_coord[2];
	char* start;

	i = 0;
	board_coord[0] = 0;
	board_coord[1] = 0;
	if(str)
	{
		if((start = ft_strstr((const char*)str, "Plateau ")))
		{
			ft_board_size(start, board_coord); // board size
		}
		if ((start = ft_strstr((const char*)str, PLAYER_NAME)))
		{
			// ft_putstr_fd(ft_itoa(ft_player_number(start)), 2); //player number... useless?
		}
		if ((start = ft_strstr((const char*)str, "Piece ")))
		{
			ft_putstr_fd(map, 2);
			ft_play(8, 2);
		}
	}
	return ;
}


void	ft_read()
{
	char*	line;
	char*	stock;
	char*	map;
	int		ret;

	if (!(map = ft_strnew(BUFFSIZE)))
		return ;
	if (!(line = ft_strnew(BUFFSIZE)))
		return ;
	if (!(stock = ft_strnew(BUFFSIZE)))
		return ;
	while((ret = get_next_line(FD, &line)) > 0)
	{
		if(ft_isdigit(line[0]))
		{
			map = ft_mystrjoin_and_free(map, line);
		}
		stock = ft_mystrjoin_and_free(stock, line);
		ft_check_plateau(stock, map);
	}
	return ;
}

// void	ft_read()
// {
// 	char*	line;
// 	char*	stock;
// 	int		ret;

// 	if (!(line = ft_strnew(BUFFSIZE)))
// 		return ;
// 	if (!(stock = ft_strnew(BUFFSIZE)))
// 		return ;
// 	while((ret = read(FD, line, BUFFSIZE)) > 0)
// 	{
// 		line[ret] = '\0';
// 		stock = ft_mystrjoin_and_free(stock, line);
// 		ft_check_plateau(stock);
// 	}

// 	return ;
// }

int	main(void)
{
	ft_read();
	return (0);
}