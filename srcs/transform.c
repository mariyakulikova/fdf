/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:23:23 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/28 15:34:57 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_dot *dot)
{
	int	temp;

	temp = dot->x;
	dot->x = ((temp - dot->y) * cos(0.523599)) + WIDTH / 3;
	dot->y = ((temp + dot->y) * sin(0.523599) - dot->z) + HEIGHT / 3;
}

void	zoom(t_dot *dot, int scale, int z_scale)
{
	dot->x *= scale;
	dot->y *= scale;
	dot->z *= z_scale;
}

void	shift(t_dot *dot, int shift)
{
	dot->x += shift;
	dot->y += shift;
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
			zoom(params->map[y][x], params->scale, params-> z_scale);
			isometric(params->map[y][x]);
			shift(params->map[y][x], params->shift);
		}
	}
}
