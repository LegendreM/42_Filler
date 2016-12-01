#include "filler.h"

void	play(int x, int y)
{
//	char	*x_str;
//	char	*y_str;

//			ft_putnbr_fd(x, 2);
//	if ((x_str = ft_itoa(x)))
//	{
//		if ((y_str = ft_itoa(y)))
//		{
			//write(2, x_str, ft_strlen(x_str));
			ft_putnbr_fd(x, 1);
			write(1, " ", 1);
			ft_putnbr_fd(y, 1);
			//write(2, y_str, ft_strlen(y_str));
			write(1, "\n", 1);
//		}
//	}
	return ;
}
