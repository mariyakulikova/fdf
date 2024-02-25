/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:46:23 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/25 21:33:39 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	printf("tut");

	offset = (img->line_len * y) + (x * (img->bpp / 8));
	*((unsigned int *)(img->addr + offset)) = color;
}

void	bresenham(t_img *img, t_dot *dot1, t_dot *dot2)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	p;

	x = dot1->x;
	y = dot1->y;
	dx = dot2->x - dot1->x;
	dy = dot2->y - dot2->y;
	p = 2 * dx - dy;
	while (x <= dot2->x)
	{
		my_pixel_put(img, x, y, 0xFFFFFF);
		x++;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2* dy - 2 * dx;
			y++;
		}
	}
}

void	draw(t_params *params)
{
	t_list	*current;
	t_img	*img;

	current = params->map;
	img = &params->img;
	int i = 0;
	while (current->next)
	{
		bresenham(img, current->content, current->next->content);
		current = current->next;
		i++;
	}
	mlx_put_image_to_window(params->mlx_ptr,
							params->win_ptr,
							img->ptr,
							0, 0);
}
