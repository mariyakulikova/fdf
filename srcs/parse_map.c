/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:19:39 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/21 16:51:23 by mkulikov         ###   ########.fr       */
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
	printf("<-- count_width_and_height -->\n"); //DELETE
	printf("map_width = %d\nmap_height = %d\n", params->map_width, params->map_height); //DELETE
}

static t_dot	*parse_coord(char *s, int x, int y)
{
	char	*ptr;
	char	*color;
	int		z;
	int		c;
	t_dot	*dot;

	ptr = ft_strchr(s, ',');
	// if (!ptr)
	// 	exit(EXIT_FAILURE);
	color = ft_strdup(ptr);
	// if (!color)
	// 	exit(EXIT_FAILURE);
	z = ft_atoi(s);
	c = ft_atoi(color);
	dot = new_dot(x, y, z, c);
	// if (!dot)
	// 	exit(EXIT_FAILURE);
	return (dot);
}

static void	parse_line(char *line, t_params *params, int y)
{
	char	**arr;
	int		i;
	t_dot	*dot;
	t_list	*new;

	arr = ft_split(line, ' ');
	// if (!arr)
	// 	exit(EXIT_FAILURE);
	i = 0;
	while (*(arr + i) && (i < params->map_width))
	{
		dot = parse_coord(*(arr + i), i, params->map_height);
		new = ft_lstnew(dot);
		if (!params->last_dot)
			params->map = new;
		else
			params->last_dot->next = new;
		params->last_dot = new;
		i++;
	}
	printf("<-- parse_line -->\n");
	printf("i = %d\n", i);
}

void	parse_map(int fd, t_params *params)
{
	char	*line;
	size_t	y;

	y = params->map_height;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		parse_line(line, params, --y);
	}

}
