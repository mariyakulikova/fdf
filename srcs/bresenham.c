/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:26:26 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/26 15:11:50 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	slope_bigger_then_one(t_img *img, int dx, int dy, t_dot *a, t_dot *b)
{
	int	p;
	int	i;

	i = 0;
	p = 2 * dx - dy;
	my_pixel_put(img, a->x, a->y, 0xFFFFFF);
	while (i < dy)
	{
		a->y += 1;
		if (p < 0)
			p = p + 2 * dx;
		else
		{
			a->x += 1;
			p = p + 2 * dx - 2 * dy;
		}
		my_pixel_put(img, a->x, a->y, 0xFFFFFF);
		i++;
	}
}

void	slope_less_then_one(t_img *img, int dx, int dy, t_dot *a, t_dot *b)
{
	int	p;
	int	i;

	i = -1;
	p = 2 * (int)abs(dy) - (int)abs(dx);
	while (++i < (int)abs(dx))
	{
		if (dx > 0)
			a->x += 1;
		else
			a->x -= 1;
		if (p < 0)
			p = p + 2 * (int)abs(dy);
		else
		{
			if (dy > 0)
				a->y += 1;
			else
				a->y -= 1;
			p = p + 2 * (int)abs(dy) - 2 * (int)abs(dx);
		}
		my_pixel_put(img, a->x, a->y, 0xFFFFFF);
	}
}

void	bresenham(t_img *img, t_dot *a, t_dot *b)
{
	int	dx;
	int	dy;

	dx = b->x - a->x;
	dy = b->y - a->y;
	if ((int)abs(dx) > (int)abs(dy))
		slope_less_then_one(img, dx, dy, a, b);
	else
		slope_bigger_then_one(img, dx, dy, a, b);
}
