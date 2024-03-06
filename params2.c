/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:34:02 by mkulikov          #+#    #+#             */
/*   Updated: 2024/03/06 15:20:53 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_zoom_ratio(t_params *params)
{
	double	map_width;
	double	map_height;
	double	zoom_ratio_x;
	double	zoom_ratio_y;

	if (params->map_height < 20 && params->map_width)
	{
		params->zoom_ratio = 2.0;
		return ;
	}
	map_width = (double)(params->max_x - params->min_x);
	map_height = (double)(params->max_y - params->min_y);
	zoom_ratio_x = (double)WIDTH * WIN_CEF / map_width;
	zoom_ratio_y = (double)HEIGHT * WIN_CEF / map_height;
	params->zoom_ratio = get_dmin(zoom_ratio_x, zoom_ratio_y);
}
