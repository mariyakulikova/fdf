/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:22:34 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/16 21:36:49 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	start_window(t_params *params)
{
	params->mlx_ptr = mlx_init();
	if (!params->mlx_ptr)
		return (MLX_ERROR);
	params->win_ptr = mlx_new_window(params->mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!params->win_ptr)
	{
		mlx_destroy_display(params->mlx_ptr);
		free(params->mlx_ptr);
		return (MLX_ERROR);
	}
	mlx_key_hook(params->win_ptr, key_hook, params);
	mlx_hook(params->win_ptr, DestroyNotify, 0, close_window, params);
	mlx_loop(params->mlx_ptr);
	return (0);
}

int	close_window(t_params *params)
{
	mlx_destroy_window(params->mlx_ptr, params->win_ptr);
	mlx_destroy_display(params->mlx_ptr);
	exit(0);
	return (0);
}

