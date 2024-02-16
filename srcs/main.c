/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:46:52 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/16 21:39:21 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	validate_argv(int argc, char **argv)
{
	if (argc > 2)
	{
		ft_putstr_fd("Argument list too long\n", 2);
		return (1);
	}
	if (argc != 2)
	{
		ft_putstr_fd("No argument\n", 2);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_params	*params;

	params = (t_params *)malloc(sizeof(t_params));
	if (validate_argv(argc, argv))
		return (1);
	if (process_file(*(argv + 1), params))
		return (1);
	start_window(params);
	free_params(params);
	return (0);
}
