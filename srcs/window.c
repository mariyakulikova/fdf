/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:22:34 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/14 15:04:27 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	start_window(t_vars *vars)
{
	vars->mlx_ptr = mlx_init();
	if (!vars->mlx_ptr)
		return (MLX_ERROR);
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!vars->win_ptr)
	{
		mlx_destroy_display(vars->mlx_ptr);
		free(vars->mlx_ptr);
		return (MLX_ERROR);
	}
	mlx_key_hook(vars->win_ptr, key_hook, vars);
	mlx_hook(vars->win_ptr, DestroyNotify, 0, close_window, vars);
	mlx_loop(vars->mlx_ptr);
	return (0);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->mlx_ptr);
	exit (0);
	return (0);
}

