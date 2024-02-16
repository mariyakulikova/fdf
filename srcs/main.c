/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manya <manya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:46:52 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/16 10:42:16 by manya            ###   ########.fr       */
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
	t_vars	vars;

	if (validate_argv(argc, argv))
		return (1);
	if (process_file(*(argv + 1), &vars))
		return (1);
	start_window(&vars);
	return (0);
}
