/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:23:23 by mkulikov          #+#    #+#             */
/*   Updated: 2024/03/06 14:48:31 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_and_shift(t_params *params, t_dot *dot)
{
	dot->x = dot->x * params->zoom_ratio + params->offset_x;
	dot->y = dot->y * params->zoom_ratio + params->offset_y;
}

void	transform_map(t_params *params)
{
	int	y;
	int	x;

	y = -1;
	while (++y < params->map_height)
	{
		x = -1;
		while (++x < params->map_width)
		{
			isometric(params->map[y][x], params->angle);
			set_max_min(params, params->map[y][x]);
		}
	}
	set_offset_x_y(params);
	set_zoom_ratio(params);
	y = -1;
	while (++y < params->map_height)
	{
		x = -1;
		while (++x < params->map_width)
			zoom_and_shift(params, params->map[y][x]);
	}
}
