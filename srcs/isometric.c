/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:40:19 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/28 16:42:51 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_rot(t_dot *dot, double teta)
{
	dot->y = dot->y * cos(teta) + dot->z * sin(teta);
	dot->z = -(dot->y) * sin(teta) + dot->z * (cos(teta));
}

void	y_rot(t_dot *dot, double teta)
{
	dot->x = dot->x * cos(teta) + dot->z * sin(teta);
	dot->z = -(dot->x) * sin(teta) + dot->z * (cos(teta));
}

void	z_rot(t_dot *dot, double teta)
{
	dot->x = dot->x * cos(teta) - dot->y * sin(teta);
	dot->y = (dot->x) * sin(teta) + dot->y * (cos(teta));
}
