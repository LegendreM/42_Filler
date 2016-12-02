#include "libft.h"
#include <stdlib.h>

char	**ft_matrixnew(const size_t y, const size_t x)
{
	char		**map;
	size_t		i;
	size_t		size;

	i = 1;
	size = y * x;
	if (!(map = (char**)malloc(sizeof(char*) * y)))
		return (NULL);
	if (!(map[0] = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(map[0], size);
	while (i < y)
	{
		map[i] = map[i - 1] + x;
		++i;
	}
	return (map);
}
