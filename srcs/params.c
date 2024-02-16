/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:30:09 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/16 22:07:05 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot_param	*new_dot(int x, int y, int z)
{
	t_dot_param	*dot;

	dot = (t_dot_param *)malloc(sizeof(t_dot_param));
	dot->x = (float)x;
	dot->y = (float)y;
	dot->z = (float)z;
	dot->shift_x = 100;
	dot->shift_y = 100;
	dot->angle = 120; //0.523599
	return (dot);
}
static void	free_dot(void *dot)
{
	free(dot);
}

void	free_params(t_params *params)
{
	ft_lstclear(&params->map, &free_dot);
	free(params->map);
	free(params->mlx_ptr);
	free(params);
}
