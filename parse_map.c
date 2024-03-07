/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:19:39 by mkulikov          #+#    #+#             */
/*   Updated: 2024/03/07 12:55:06 by mkulikov         ###   ########.fr       */
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
	params->map_width = (int)ft_count_words(line, ' ');
	params->map_height = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			params->map_height++;
	}
}

t_dot	*parse_coord(char *s, int x, int y, t_params *params)
{
	char	*ptr;
	char	*color;
	int		z;
	int		c;
	t_dot	*dot;

	z = ft_atoi(s);
	dot = new_dot(-STEP * params->map_width / 2 + STEP * x, \
					-STEP * params->map_height / 2 + STEP * y, z, 0xFFFFFF);
	if (!dot)
		exit(EXIT_FAILURE);
	return (dot);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (*(split + i))
	{
		free(*(split + i));
		i++;
	}
	free(split);
}

static void	parse_line(char *line, t_params *params, int y)
{
	char	**arr;
	int		x;
	t_dot	*dot;
	t_dot	***map;

	arr = ft_split(line, ' ');
	if (!arr)
		exit(EXIT_FAILURE);
	x = 0;
	map = params->map;
	*(map + y) = (t_dot **)malloc(sizeof(t_dot *) * params->map_width);
	while (*(arr + x) && (x < params->map_width))
	{
		dot = parse_coord(*(arr + x), x, y, params);
		*(*(map + y) + x) = dot;
		x++;
	}
	free_split(arr);
}

void	parse_map(int fd, t_params *params)
{
	char	*line;
	int		y;

	y = 0;
	params->map = (t_dot ***)malloc(sizeof(t_dot **) * params->map_height);
	if (!params->map)
		exit(EXIT_FAILURE);
	while (y < params->map_height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		parse_line(line, params, y);
		free(line);
		y++;
	}
}
