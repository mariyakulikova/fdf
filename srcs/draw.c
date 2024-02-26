/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:46:23 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/26 11:14:37 by mkulikov         ###   ########.fr       */
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

void	bresenham(t_img *img, int x1, int y1, int x2, int y2)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	p;

	x = x1;
	y = y;
	dx = dot2->x - dot1->x;
	dy = dot2->y - dot1->y;
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

void	draw_map(t_params *params)
{
	t_list	*current;
	t_img	*img;
	int		i;
	int		j;

	current = params->map;
	img = &params->img;
	while (current->next)
	{
		bresenham(img, current->content, current->next->content);
		current = current->next;
	}
	i = 0;
	while (i < params->map_height)
	{
		j = 0;
		while (j < params->map_width)
		{
			/* code */
		}

	}
	mlx_put_image_to_window(params->mlx_ptr,
							params->win_ptr,
							img->ptr,
							0, 0);
}
