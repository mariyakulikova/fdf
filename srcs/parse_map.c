/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:19:39 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/21 13:41:56 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	count_width_and_height(int fd, t_params *params)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		ft_putstr_fd("Map is empty!\n", 2);
		exit(EXIT_SUCCESS);
	}
	params->map_width = ft_count_words(line, ' ');
	params->map_height = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			params->map_height++;
	}
	printf("<-- count_width_and_height -->\n"); //DELETE
	printf("map_width = %ld\nmap_height = %ld\n", params->map_width, params->map_height); //DELETE
}

void	parse_map(int fd, t_params *params)
{
	printf("parse_map\n");
}
