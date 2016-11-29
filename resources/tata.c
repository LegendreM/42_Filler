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

t_params	*ft_init_board(char *start, t_params *params) //work
{
	int i;

	i = 0;
	params = (t_params*)malloc(sizeof(t_params));
	while(ft_isalpha(start[i]))
		++i;
	++i;
	
	params->board_size.x = ft_atoi(&start[i]);
	while(ft_isdigit(start[i]))
		++i;
	params->board_size.y = ft_atoi(&start[i]);
	params->player = 0;
	params->count_line = 0;
	return (params);
}

int	ft_player_number(char *start, t_params *params) //work
{

	if (ft_atoi(&start[-4]) == 1)
		params->player = 'o';
	else if (ft_atoi(&start[-4]) == 2)
		params->player = 'x';
	else
		return (-1);
	return (0);
}

void	ft_play(int x, int y) //work
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

// char	**ft_matrixnew(const size_t width, const size_t height)
// {
// 	char		**map;
// 	int 		i = 0;
// 	size_t		size;

// 	size = width * (height + 1);
// 	if (!(map = (char**)malloc(sizeof(char*) * width + 1)))
// 		return (NULL);	
// 	map[width] = NULL;
// 	if (!(map[0] = (char*)malloc(sizeof(char) * size)))
// 		return (NULL);
// 	ft_bzero(map[0], size);

// 	i = 1;
// 	while (map[i])
// 	{
// 		// map[i] = &(map[i - 1][height + 1]);
// 		map[i] =  map[i - 1] + height + 1;
// 	}
// 	return (map);
// }


// void	ft_save_map(char *str, t_params *params)
// {
// 	params->game_board = ft_matrixnew(params->board_size->x, params->board_size->y);
// 	return ;
// }

t_params	*ft_check_input(char *str, t_params *params) //work but useless
{
	int i;
	char* start;

	i = 0;
	if (str)
	{
		if (params == NULL && (start = ft_strstr((const char*)str, "Plateau ")))
		{
			params = ft_init_board(start, params); // board size
		}
		if (params != NULL && params->player == 0 && (start = ft_strstr((const char*)str, PLAYER_NAME)))
		{
			ft_player_number(start, params);
		}
		if (ft_isdigit(str[0]))
		{
			// ft_save_map(str, params); // on working
			// ++params->count_line;
		}

		if ((start = ft_strstr((const char*)str, "Piece ")))
		{
			ft_play(0, 0);
		}
	}
	return (params);
}


void	ft_read()
{
	char		*line;
	char		*map;
	t_params	*params;
	int			ret;

	params = NULL;
	if (!(map = ft_strnew(BUFFSIZE)))
		return ;
	while ((ret = get_next_line(FD, &line)) > 0)
	{
		params = ft_check_input(line, params);
	}
	return ;
}

int	main(void)
{
	ft_read();
	return (0);
}