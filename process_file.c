/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:42:49 by mkulikov          #+#    #+#             */
/*   Updated: 2024/03/06 17:01:42 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	open_file(char *path, t_params *params)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Oops!");
		free(params);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	process_file(char *path, t_params *params)
{
	int	fd;

	fd = open_file(path);
	count_width_and_height(fd, params);
	close(fd);
	fd = open_file(path);
	parse_map(fd, params);
	close(fd);
}
