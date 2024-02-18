#include "fdf.h"

static void	print_dot(void *_dot)
{
	t_dot_param *dot = (t_dot_param *)_dot;
	printf("x - %f, y - %f, z - %f\n", dot->x, dot->y, dot->z);
}

void	test(t_params *params)
{
	printf("list size - %d\n", ft_lstsize(params->map));
	ft_lstiter(params->map, &print_dot);
}
