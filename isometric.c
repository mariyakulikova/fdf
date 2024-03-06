/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:40:19 by mkulikov          #+#    #+#             */
/*   Updated: 2024/03/06 15:18:32 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_dot *dot, double angle)
{
	int	temp;

	temp = dot->x;
	dot->x = ((temp - dot->y) * cos(angle));
	dot->y = ((temp + dot->y) * sin(angle) - dot->z);
}
