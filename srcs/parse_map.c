/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:19:39 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/19 11:14:42 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	parse_line(char *line, t_params *params)
{
	char		**arr;
	int			x;
	t_list		*new;
	t_dot_param	*dot;

	arr = ft_split(line, ' ');
	if (!arr)
		exit(1);
	x= 0;
	while (*(arr + x))
	{
		dot = new_dot(x, params->map_height, (float)ft_atoi(*(arr + x)));
		new = ft_lstnew(new_dot);
		if (!params->last_dot)
			params->map = new;
		else
			params->last_dot->next = new;
		params->last_dot = new;
		x++;
	}
	params->map_width = x;
	while (*(arr + --x))
		free(*(arr + x));
	free(arr);
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
	printf("map width - %ld, height - %ld\n", params->map_width, params->map_height);
	test(params);
	return (0);
}
