#define BUFFSIZE 8
#define FD 0

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

void	ft_check_plateau(char *str)
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
			ft_board_size(start, board_coord);
			ft_putstr_fd("\n", 2);//
			ft_putstr_fd(ft_itoa(board_coord[0]), 2);//
			ft_putstr_fd(" ", 2);//
			ft_putstr_fd(ft_itoa(board_coord[1]), 2);//
			ft_putstr_fd("\n", 2);//
		}
		else
			ft_putstr_fd("not yet", 2);
	}
	return ;
}


void	ft_read()
{
	char*	line;
	char*	stock;
	int		ret;

	if (!(line = ft_strnew(BUFFSIZE)))
		return ;
	if (!(stock = ft_strnew(BUFFSIZE)))
		return ;
	while((ret = read(FD, line, BUFFSIZE)) > 0)
	{
		line[ret] = '\0';
		stock = ft_mystrjoin_and_free(stock, line);
		ft_check_plateau(stock);
	}

	return ;
}

int	main(void)
{
	ft_read();
	return (0);
}