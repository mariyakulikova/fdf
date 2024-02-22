/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:30:09 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/22 16:32:22 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot	*new_dot(int x, int y, int z, int c)
{
	t_dot	*dot;

	dot = (t_dot*)malloc(sizeof(t_dot));
	if (!dot)
		return (NULL);
	dot->x = x;
	dot->y = y;
	dot->z = z;
	if (c)
		dot->color = c;
	else
		dot->color = 0xFFFFFF;
	return (dot);
}

t_params	*params_init(void)
{
	t_params	*params;

	params = (t_params*)malloc(sizeof(t_params));
	if (!params)
		return (NULL);
	params->map = NULL;
	params->last_dot = NULL;
	params->map_height = 0;
	params->map_width = 0;
	return (params);
}

void	free_params(t_params *params)
{
	free(params->mlx_ptr);
	ft_lstclear(&params->map, free);
	free(params);
}
