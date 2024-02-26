/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:46:23 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/26 15:36:49 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bpp / 8));
	*((unsigned int *)(img->addr + offset)) = color;
}


void	draw_map(t_params *params)
{
	int		x;
	int		y;
	t_dot	***map;

	y = 0;
	map = params->map;
	while (y < params->map_height - 1)
	{
		x = 0;
		while (x < params->map_width - 1)
		{
			bresenham(&params->img, map[y][x], map[y][x + 1]);
			bresenham(&params->img, map[y][x], map[y + 1][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(params->mlx_ptr, \
							params->win_ptr, \
							params->img.ptr, \
							0, 0);
}
