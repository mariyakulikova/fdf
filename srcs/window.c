/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:22:34 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/20 18:30:16 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_mlx(t_params *params)
{
	// t_img	*img;

	params->mlx_ptr = mlx_init();
	params->win_ptr = mlx_new_window(params->mlx_ptr, WIDTH, HEIGHT, TITLE);
	params->img.ptr = mlx_new_image(params->mlx_ptr, WIDTH, HEIGHT);
	// img = params->img;
	params->img.addr = mlx_get_data_addr(params->img.ptr, \
									&(params->img.bpp), \
									&(params->img.line_len), \
									&(params->img.endian));
	mlx_key_hook(params->win_ptr, key_hook, params);
	mlx_hook(params->win_ptr, DestroyNotify, 0, close_window, params);
	mlx_loop(params->mlx_ptr);
}

int	close_window(t_params *params)
{
	mlx_loop_end(params->mlx_ptr);
	// mlx_destroy_image(params->mlx_ptr, params->img.ptr);
	mlx_destroy_window(params->mlx_ptr, params->win_ptr);
	mlx_destroy_display(params->mlx_ptr);
	return (0);
}

