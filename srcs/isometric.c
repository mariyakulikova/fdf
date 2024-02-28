/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:40:19 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/28 17:12:13 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_dot *dot, double angle)
{
	int	temp;

	temp = dot->x;
	dot->x = ((temp - dot->y) * cos(angle));
	dot->y = ((temp + dot->y) * sin(angle) - dot->z);
}

void	x_rot(t_dot *dot, double angle)
{
	dot->y = dot->y * cos(angle) + dot->z * sin(angle);
	dot->z = -(dot->y) * sin(angle) + dot->z * (cos(angle));
}

void	y_rot(t_dot *dot, double angle)
{
	dot->x = dot->x * cos(angle) + dot->z * sin(angle);
	dot->z = -(dot->x) * sin(angle) + dot->z * (cos(angle));
}

void	z_rot(t_dot *dot, double angle)
{
	dot->x = dot->x * cos(angle) - dot->y * sin(angle);
	dot->y = (dot->x) * sin(angle) + dot->y * (cos(angle));
}
