/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:23:23 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/26 16:34:29 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_dot *dot)
{
	int	tmp;

	tmp = dot->x;
	dot->x = (tmp - dot->y) * cos(0.523599);
	dot->y = (tmp + dot->y) * sin(0.523599) - dot->z;
	printf("tut");
}
