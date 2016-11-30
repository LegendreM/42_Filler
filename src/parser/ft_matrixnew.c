#include "libft.h"
#include <stdlib.h>

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
