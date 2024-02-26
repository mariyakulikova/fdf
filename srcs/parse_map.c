/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:19:39 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/26 10:57:01 by mkulikov         ###   ########.fr       */
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
	if (!dot)
		exit(EXIT_FAILURE);
	return (dot);
}

static void	parse_line(char *line, t_params *params, int y)
{
	char	**arr;
	int		i;

	arr = ft_split(line, ' ');
	if (!arr)
		exit(EXIT_FAILURE);
	i = 0;
	*(params->tab + y) = (int *)malloc(sizeof(int) * params->map_width);
	while (*(arr + i) && (i < params->map_width))
	{
		*(*(params->tab + y) + i) = ft_atoi(*(arr + i));
		add_dot(params, *(arr + i), i, params->map_height);
		i++;
	}
	i--;
	while (i >= 0)
		free(*(arr + i--));
	free(arr);
}

void	parse_map(int fd, t_params *params)
{
	char	*line;
	size_t	y;

	y = params->map_height;
	params->tab = (int **)malloc(sizeof(int *) * y);
	if (!params->tab)
		exit(EXIT_FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		parse_line(line, params, --y);
		free(line);
	}
}
