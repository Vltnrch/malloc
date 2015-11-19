#include "malloc.h"

int	main()
{
	char	*addr;

	addr = ft_malloc(16);
	ft_free(NULL);
	ft_free((void *)addr + 5);
	if (ft_realloc((void *)addr + 5, 10) == NULL)
		print("Bonjours\n");
	return (0);
}