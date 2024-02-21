/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:46:52 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/21 12:48:06 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	validate_argv(int argc, char **argv)
{
	if (argc > 2)
		ft_putstr_fd("Argument list too long\n", 2);
	if (argc != 2)
		ft_putstr_fd("No argument\n", 2);
	return (0);
}



int	main(int argc, char **argv)
{
	t_params	params;

	if (validate_argv(argc, argv))
		return (0);
	process_file(*(argv + 1), &params);
	start_mlx(&params);
	return (0);
}
