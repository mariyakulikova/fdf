/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:46:23 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/26 15:04:48 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bpp / 8));
	*((unsigned int *)(img->addr + offset)) = color;
}


void	draw(t_params *params)
{
	int		x;
	int		y;

	y = 0;
	while (y < params->map_height)
	{
		x = 0;
		while (x < params->map_width)
		{
			bresenham(&params->img, *(*(params->map + y) + x), *(*(params->map + y) + x  + 1));
			bresenham(&params->img, *(*(params->map + y) + x), *(*(params->map + y + 1) + x));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(params->mlx_ptr,
							params->win_ptr,
							img->ptr,
							0, 0);
}
