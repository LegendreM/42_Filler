#include "get_next_line.h"
#include "libft.h"

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
  if (start[i])
    return (0);
  return (1);
}

void	print(int x, int y)
{
  ft_putstr(ft_itoa(y));
  ft_putchar(' ');
  ft_putstr(ft_itoa(x));
  ft_putchar('\n');
}

int	main()
{
  char*	line;

  line = NULL;
  while (get_next_line(0, &line) > 0)
    {
      ft_putstr_fd("main()\n", 2);
      ft_putstr_fd(line, 2);
      ft_putstr_fd("\n", 2);
      if (strstart(line, "$$$"))
	{
	}
      if (strstart(line, "Plateau"))
	{
	  ft_putstr_fd("Plateau\n", 2);
	}
      if (strstart(line, "Piece"))
	{
	  ft_putstr_fd("Piece\n", 2);
	  ft_putstr_fd("back in main", 2);
	  print(8, 2);
	}
    }
  return (0);
}
