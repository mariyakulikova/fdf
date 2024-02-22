#include "fdf.h"


static void	f(void *content)
{
	t_dot *dot = (t_dot*)content;
	printf("x = %f y = %f z = %f\n", dot->x, dot->y, dot->z);
}

void	test_print(t_list *map)
{
	ft_lstiter(map, f);
}
