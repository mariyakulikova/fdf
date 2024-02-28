/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:23:23 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/28 11:29:48 by mkulikov         ###   ########.fr       */
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
