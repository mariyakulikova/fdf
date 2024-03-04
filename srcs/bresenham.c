/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:26:26 by mkulikov          #+#    #+#             */
/*   Updated: 2024/03/04 12:39:00 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	setup_vars(t_bresenham_var *vars, t_dot a, t_dot b)
{
	vars->dx = b.x - a.x;
	vars->dy = b.y - a.y;
	vars->x_er = 0;
	vars->y_er = 0;
	if (vars->dx > 0)
		vars->x_inc = 1;
	else if (vars->dx != 0)
		vars->x_inc = -1;
	if (vars->dy > 0)
		vars->y_inc = 1;
	else if (vars->dy != 0)
		vars->y_inc = -1;
	vars->dx = abs(vars->dx);
	vars->dy = abs(vars->dy);
	if (vars->dx > vars->dy)
		vars->d = vars->dx;
	else
		vars->d = vars->dy;
}

void	bresenham8(t_img *img, t_dot a, t_dot b)
{
	t_bresenham_var	vars;
	int				i;

	setup_vars(&vars, a, b);
	i = 0;
	while (i++ < vars.d)
	{
		my_pixel_put(img, a.x, a.y, 0xFF0000);
		vars.x_er += vars.dx;
		vars.y_er += vars.dy;
		if (vars.x_er >= vars.d)
		{
			a.x += vars.x_inc;
			vars.x_er -= vars.d;
		}
		if (vars.y_er >= vars.d)
		{
			a.y += vars.y_inc;
			vars.y_er -= vars.d;
		}
	}
}
