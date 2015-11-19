#include "malloc.h"

int	main()
{
	int		i;
	char	*addr[1024];

	i = 0;
	while (i < 1024)
	{
		addr[i] = (char *)ft_malloc(1024);
		i++;
	}
	show_alloc_mem();
	i = 0;
	while (i < 1024)
	{
		ft_free(addr[i]);
		i++;
	}
	show_alloc_mem();
	return (0);
}