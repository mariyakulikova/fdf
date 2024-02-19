/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:19:39 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/18 17:14:31 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	*parse_line(char *line, t_params *params)
{
	char	**splited;
	int		x;
	t_list	*new;

	splited = ft_split(line, ' ');
	if (!splited)
		return (NULL);
	x= 0;
	while (*(splited + x))
	{
		new = ft_lstnew(new_dot(x, params->map_height, (float)ft_atoi(*(splited + x++))));
		if (!params->last_dot)
			params->map = new;
		else
			params->last_dot->next = new;
		params->last_dot = new;
	}
	// free(new);
	params->map_width = x;
	x = 0;
	while (*(splited + x))
		free(*(splited + x++));
	free(splited);
}

int	parse_map(int fd, t_params *params)
{
	char	*line;

	params->map_height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!*line)
			break ;
		parse_line(line, params);
		params->map_height += 1;
		free(line);
	}
	// free(line);
	printf("map width - %ld, height - %ld\n", params->map_width, params->map_height);
	test(params);
	return (0);
}
