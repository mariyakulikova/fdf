/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:46:52 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/12 16:39:58 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	void	*mlx;
	void	*window;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	window = mlx_new_window(mlx, 800, 600, "MY PERFECT WINDOW");
	if (!window)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		return (1);
	}
	mlx_loop(mlx);
	mlx_destroy_window(mlx, window);
	mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}
