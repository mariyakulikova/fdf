/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:47:12 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/26 14:50:22 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include "libft.h"
# include "mlx.h"

# define HEIGHT 600
# define WIDTH 900
# define TITLE "FdF"

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_dot {
	int			x;
	int			y;
	int			z;
	unsigned int	color;
}			t_dot;

typedef struct s_params {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_dot	***map;
	int		map_width;
	int		map_height;
	t_list	*last_dot;
}			t_params;

void		start_mlx(t_params *params);
int			close_window(t_params *params);
int			key_hook(int keysym, t_params *params);
void		process_file(char *path, t_params *params);
void		count_width_and_height(int fd, t_params *params);
void		free_params(t_params *params);
void		parse_map(int fd, t_params *params);
t_dot		*new_dot(int x, int y, int z, int c);
void		test_print(t_list *map);
t_params	*params_init(void);
void		draw_map(t_params *params);
t_dot		*parse_coord(char *s, int x, int y);
void		add_dot(t_params *params, char *i, int x, int y);
void		bresenham(t_img *img, t_dot *a, t_dot *b);
void		my_pixel_put(t_img *img, int x, int y, int color);

#endif
