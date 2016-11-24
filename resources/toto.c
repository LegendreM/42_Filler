
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"


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


void	ft_play()
{
  write(1, "8 2\n", 4);
  return ;
}

void	ft_read_map()
{
  char*	line;
  int	ret;

  ret = 0;
  line = NULL;
  while(get_next_line(0, &line) > 0)
    {

      if (strstart(line, "Piece"))
	{
	  ft_play();
	}
     }
  return ;
}

int	main(int ac, char** av)
{
  (void)ac;
  (void)av;
  ft_read_map();
  ft_play();
  return (0);
}
