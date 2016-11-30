#define BUFFSIZE 8
#define FD 0
#define PLAYER_NAME "[players/tata.filler]"

#include <unistd.h>//read
#include "libft.h"
#include "get_next_line.h"
#include "filler.h"

char	**ft_matrixnew(const size_t y, const size_t x)
{
	char		**map;
	size_t		i;
	size_t		size;

	size = y * (x + 1);
	if (!(map = (char**)malloc(sizeof(char*) * y + 1)))
		return (NULL);
	map[y] = NULL;
	if (!(map[0] = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(map[0], size);

	i = 1;
	while (i < y)
	{
		// map[i] = &(map[i - 1][height + 1]);
		map[i] = map[i - 1] + x + 1;
		i++;
	}
	return (map);
}


t_params	*ft_init_board(char *start, t_params *params) //work
{
	int i;

	i = 0;
	params = (t_params*)malloc(sizeof(t_params));
	while(ft_isalpha(start[i]))
		++i;
	++i;

	params->board_size.y = ft_atoi(&start[i]);
	while(ft_isdigit(start[i]))
		++i;
	params->board_size.x = ft_atoi(&start[i]);
	params->game_board = ft_matrixnew(params->board_size.y,
							params->board_size.x);
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

void	ft_get_piece(char *line, t_params *params)
{
	int		i;

	i = 0;
	while(ft_isalpha(line[i]) || line[i] == ' ')
		++i;
	params->piece_size.y = ft_atoi(&line[i]);
	while(ft_isdigit(line[i]))
		++i;
	params->piece_size.x = ft_atoi(&line[i]);
	params->game_piece = ft_matrixnew(
							params->piece_size.y,
							params->piece_size.x
						);
	i = 0;
	while (i < params->piece_size.y)
	{
		get_next_line(FD, &line);
		ft_strncpy(
			params->game_piece[i],
			line,
			params->piece_size.x
		);
		i++;
	}
}

void		ft_fill_matrix(const char *line, t_params *params)
{
	ft_strncpy(
		params->game_board[params->count_line],
		line + 4,
		params->board_size.x
	);
	params->count_line++;
}

t_params	*ft_check_input(char *str, t_params *params) //work
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
			ft_fill_matrix((const char *)str, params);
		}
		if ((start = ft_strstr((const char*)str, "Piece ")))
		{
			ft_get_piece(start, params); // need to work on that
				play(0, 0);
		}
	}
	return (params);
}

void		print_matrix(char **map)
{
	while (*map)
	{
		ft_putendl_fd(*map++, 2);
	}
}

t_params	*parser(void)
{
	char		*line;
	char		*map;
	t_params	*params;
	int			ret;

	params = NULL;
	if (!(map = ft_strnew(BUFFSIZE)))
		return NULL;
	while ((ret = get_next_line(FD, &line)) > 0)
	{
		params = ft_check_input(line, params);
	}
	// It returns a filled matrix, now need to check if it works multiple times
	print_matrix(params->game_board);
	print_matrix(params->game_piece);
	return params;
}

// int	parser(void)
// {
// 	ft_read();
// 	return (0);
// }
