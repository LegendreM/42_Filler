#include "libft.h"
#include <unistd.h>

void	play(int x, int y)
{
	char	*x_str;
	char	*y_str;

	if ((x_str = ft_itoa(x)))
	{
		if ((y_str = ft_itoa(y)))
		{
			write(1, x_str, ft_strlen(x_str));
			write(1, " ", 1);
			write(1, y_str, ft_strlen(y_str));
			write(1, "\n", 1);
		}
	}
	return ;
}
