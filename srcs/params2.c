/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:34:02 by mkulikov          #+#    #+#             */
/*   Updated: 2024/03/05 20:45:29 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_zoom_ratio(t_params *params)
{
	double	zoom_ratio_x;
	double	zoom_ratio_y;

	zoom_ratio_x = (double)WIDTH * 0.9 / (double)(params->max_x - params->min_x);
	zoom_ratio_y = (double)HEIGHT / (double)(params->max_y - params->min_y);
	printf("zoom_ratio_x - %f, zoom_ratio_y - %f\n", zoom_ratio_x, zoom_ratio_y);

	params->zoom_ratio = get_dmin(zoom_ratio_x, zoom_ratio_y);
}
