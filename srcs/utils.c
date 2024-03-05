/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:15:30 by mkulikov          #+#    #+#             */
/*   Updated: 2024/03/05 20:39:53 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

double	get_dmin(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}
