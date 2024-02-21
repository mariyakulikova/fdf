/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:30:09 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/21 16:50:02 by mkulikov         ###   ########.fr       */
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
	dot->color = c;
	return (dot);
}

void	free_params(t_params *params)
{
	free(params->mlx_ptr);
}
