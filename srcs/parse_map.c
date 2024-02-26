/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:19:39 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/26 15:53:11 by mkulikov         ###   ########.fr       */
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
int q = 0;

t_dot	*parse_coord(char *s, int x, int y)
{
	char	*ptr;
	char	*color;
	int		z;
	int		c;
	t_dot	*dot;

	ptr = ft_strchr(s, ',');
	if (ptr)
	{
		color = ft_strdup(ptr + 1);
		c = ft_atoi(color);
		free(color);
	}
	z = ft_atoi(s);
	dot = new_dot(x, y, z, c);
	q++;
	if (!dot)
		exit(EXIT_FAILURE);
	return (dot);
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
		dot = parse_coord(*(arr + x), x, y);
		*(*(map + y) + x) = dot;
		x++;
	}
	x--;

	while (x >= 0)
		free(*(arr + x--));
	free(arr);
}

void	parse_map(int fd, t_params *params)
{
	char	*line;
	size_t	y;

	y = params->map_height;
	params->map = (t_dot ***)malloc(sizeof(t_dot **) * y);
	if (!params->map)
		exit(EXIT_FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		parse_line(line, params, --y);
		free(line);
	}
	printf("q - %d\n", q);
}
