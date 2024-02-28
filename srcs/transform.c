/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:23:23 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/28 17:13:21 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



void	zoom(t_dot *dot, int scale, int z_scale)
{
	dot->x *= scale;
	dot->y *= scale;
	dot->z *= z_scale;
}

void	shift(t_dot *dot, int shift)
{
	dot->x += (shift + WIDTH / 3);
	dot->y += (shift + HEIGHT / 3);
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
			isometric(params->map[y][x], params->angle);
			shift(params->map[y][x], params->shift);
		}
	}
}
