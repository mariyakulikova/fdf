/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:22:34 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/13 17:35:26 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vars	*start_window(void)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!vars)
		exit(MLX_ERROR);
	vars->mlx_ptr = mlx_init();
	if (!vars->mlx_ptr)
		exit(MLX_ERROR);
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!vars->win_ptr)
	{
		mlx_destroy_display(vars->mlx_ptr);
		free(vars->mlx_ptr);
		exit (MLX_ERROR);
	}
	mlx_key_hook(vars->win_ptr, key_hook, &vars);
	mlx_hook(vars->win_ptr, DestroyNotify, 0L, close_window, &vars);
	mlx_loop(vars->mlx_ptr);
	return (vars);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	vars->win_ptr = NULL;
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->mlx_ptr);
	free(vars);
	return (0);
}
