/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:19:39 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/16 22:08:02 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	*parse_line(char *line, t_params *params)
{
	char	**splited;
	int		x;
	t_list	*current;
	t_list	*new;

	splited = ft_split(line, ' ');
	x = 0;
	if (!splited)
		return (NULL);
	new = ft_lstnew(new_dot(x, params->map_height, (float)ft_atoi(*(splited + x))));
	params->map = new;
	current = params->map;
	while (*(splited + ++x))
	{
		new = ft_lstnew(new_dot(x, params->map_height, (float)ft_atoi(*(splited + x))));
		current->next = new;
		current = current->next;
	}
	x = 0;
	while (*(splited + x))
		free(*(splited + x++));
	free(splited);
}

int	parse_map(int fd, t_params *params)
{
	char	*line;
	t_list	*current_dot;

	line = get_next_line(fd);

	if (!*line)
		return (1);
	params->map_height = 0;
	parse_line(line, params);
	params->map_width = ft_count_words(line, ' ');
	while (*line)
	{
		params->map_height += 1;
		parse_line(line, params);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	printf("map width - %ld, height - %ld\n", params->map_width, params->map_height);
	return (0);
}
