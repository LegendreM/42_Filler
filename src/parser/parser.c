#define BUFFSIZE 8
#define FD 0
#define PLAYER_NAME "[players/tata.filler]"

#include "filler.h"

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
	params->game_piece = NULL;
	params->game_piece_min = NULL;
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

void	set_piece_size(char *line, t_params *params)
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
	return ;
}

t_coord	find_piece_min_origin(char **piece, const t_coord size)
{
	t_coord	orig;
	int		x;
	int		y;

	orig.x = 1;
	orig.y = 1;
	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			if (piece[y][x] == '*')
			{
				if (- x > orig.x || orig.x == 1)
					orig.x = - x;
				if (- y > orig.y || orig.y == 1)
					orig.y = - y;
			}
			x++;
		}
		y++;
	}
	return (orig);
}

t_coord	find_piece_min_size(char **piece, const t_coord size,
			const t_coord orig)
{
	int		x;
	int		y;
	t_coord	size_min;

	size_min.x = 0;
	size_min.y = 0;
	y = - orig.y;
	while (y < size.y)
	{
		x = - orig.x;
		while (x < size.x)
		{
			if (piece[y][x] == '*')
			{
				if (y + 1 + orig.y > size_min.y)
					size_min.y = y + 1 + orig.y;
				if (x + 1 + orig.x > size_min.x)
					size_min.x = x + 1 + orig.x;
			}
			x++;
		}
		y++;
	}
	return (size_min);
}

void	ft_get_piece_min(char **piece, const t_coord size,
				t_params *params)
{
	int		y;

	y = 0;
	if (params->game_piece_min != NULL)
		free(params->game_piece_min);
	params->piece_orig = find_piece_min_origin(piece, size);
	params->piece_size_min = find_piece_min_size(piece, size,
								(const t_coord)params->piece_orig);
	params->game_piece_min
		= (char **)malloc(sizeof(params->piece_size_min.y));
	while (y < params->piece_size_min.y)
	{
		params->game_piece_min[y] = piece[y - params->piece_orig.y]
										- params->piece_orig.x;
		y++;
	}
	return ;
}

void	ft_get_piece(char *line, t_params *params)
{
	int		i;

	if (params->game_piece != NULL)
		ft_matrixdel(params->game_piece);
	set_piece_size(line, params);
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
	ft_get_piece_min(params->game_piece,
			(const t_coord)params->piece_size,
			params
		);
	return ;
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

int			ft_check_input(char *str, t_params **params)
{
	int i;
	char* start;

	i = 0;
	if (str)
	{
		if (*params == NULL && (start = ft_strstr((const char*)str, "Plateau ")))
		{
			*params = ft_init_board(start, *params);
		}
		if (*params != NULL && (*params)->player == 0 && (start = ft_strstr((const char*)str, PLAYER_NAME)))
		{
			ft_player_number(start, *params);
		}
		if (ft_isdigit(str[0]))
		{
			ft_fill_matrix((const char *)str, *params);
		}
		if ((start = ft_strstr((const char*)str, "Piece ")))
		{
			ft_get_piece(start, *params);
			return (0);
	//			play(0, 0);
		}
	}
	return (1);
}

void		print_matrix(char **map, t_coord size)
{
	int		y;

	y = 0;
	while (y < size.y)
	{
		write(2, map[y++], size.x);
		write(2, "\n", 1);
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
	while ((ret = get_next_line(FD, &line)) > 0) //gnl have issues
	{
		if (ft_check_input(line, &params) == 0)
		{

		ft_putendl_fd("Will break", 2);
			break;
		}
	}
		ft_putendl_fd("Out loop", 2);
	// It returns a filled matrix, now need to check if it works multiple times
	if (params != 0)
	{
		print_matrix(params->game_board, params->board_size);
		print_matrix(params->game_piece, params->piece_size);
		print_matrix(params->game_piece_min, params->piece_size_min);
	}
	return params;
}

// int	parser(void)
// {
// 	ft_read();
// 	return (0);
// }
