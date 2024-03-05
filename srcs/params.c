/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:30:09 by mkulikov          #+#    #+#             */
/*   Updated: 2024/03/05 15:56:43 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot	*new_dot(int x, int y, int z, int c, t_params *params)
{
	t_dot	*dot;

	dot = (t_dot *)malloc(sizeof(t_dot));
	if (!dot)
		return (NULL);
	dot->x = -STEP * params->map_width / 2 + STEP * x;
	dot->y = -STEP * params->map_height / 2 + STEP * y;
	dot->z = z;
	dot->color = c;
	return (dot);
}

t_params	*params_init(void)
{
	t_params	*params;

	params = (t_params *)malloc(sizeof(t_params));
	if (!params)
		return (NULL);
	params->map = NULL;
	params->map_height = 0;
	params->map_width = 0;
	params->max_x = 0;
	params->max_y = 0;
	params->max_x = 0;
	params->max_y = 0;
	params->offset_x = 0;
	params->offset_y = 0;
	params->scale = 10;
	params->z_scale = 2;
	params->angle = 0.523599;
	return (params);
}

void	free_params(t_params *params)
{
	int		x;
	int		y;
	t_dot	***map;

	y = params->map_height;
	map = params->map;
	free(params->mlx_ptr);
	while (--y >= 0)
	{
		x = params->map_width;
		while (--x >= 0)
			free(map[y][x]);
		free(map[y]);
	}
	free(map);
	free(params);
}

void	set_offset_x_y(t_params *params)
{
	int	win_center_x;
	int	win_center_y;
	int	pic_center_x;
	int	pic_center_y;

	win_center_x = WIDTH / 2;
	win_center_y = HEIGHT / 2;
	pic_center_x = (params->max_x - params->min_x) / 2 + params->min_x;
	pic_center_y = (params->max_y - params->min_y) / 2 + params->min_y;
	params->offset_x = win_center_x - pic_center_x;
	params->offset_y = win_center_y - pic_center_y;
}

void	set_max_min(t_params *params, t_dot *dot)
{
	params->max_x = get_max(params->max_x, dot->x);
	params->max_y = get_max(params->max_y, dot->y);
	params->min_x = get_min(params->min_x, dot->x);
	params->min_y = get_min(params->min_y, dot->y);
}
