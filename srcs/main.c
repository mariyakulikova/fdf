/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:46:52 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/14 15:38:41 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	validate_argv(int argc, char **argv)
{
	if (argc > 2)
	{
		ft_putstr_fd(strerror(E2BIG), 2);
		return (-1);
	}
	if (argc != 2)
	{
		ft_putstr_fd(strerror(EINVAL), 2);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (validate_argv(argc, argv) == -1)
		return (1);
	start_window(&vars);
	return (0);
}
