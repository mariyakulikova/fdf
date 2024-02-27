/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:23:23 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/27 16:29:57 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_dot *dot)
{
	dot->x = (dot->x - dot->y) * cos(0.523599);
	dot->y = (dot->x + dot->y) * sin(0.523599) - dot->z;
}

void	transform_iso(t_params *params)
{
	int	y;
	int	x;

	y = 0;
	while (y < params->map_height)
	{
		x = 0;
		while (x < params->map_width)
		{
			isometric(params->map[y][x]);
			x++;
		}
		y++;
	}
}
