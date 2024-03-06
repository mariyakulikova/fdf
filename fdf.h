/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:47:12 by mkulikov          #+#    #+#             */
/*   Updated: 2024/03/06 12:05:29 by mkulikov         ###   ########.fr       */
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
# define WIN_CEF 0.95
# define STEP 10
# define TITLE "FdF"

typedef struct s_bresenham_var {
	int	dx;
	int	x_inc;
	int	dy;
	int	y_inc;
	int	x_er;
	int	y_er;
	int	d;
}			t_bresenham_var;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_dot {
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}			t_dot;

typedef struct s_params {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_dot	***map;
	int		map_width;
	int		map_height;
	int		shift;
	int		scale;
	int		z_scale;
	int		min_x;
	int		min_y;
	int		max_x;
	int		max_y;
	int		offset_x;
	int		offset_y;
	double	zoom_ratio;
	double	angle;
}			t_params;

void		start_mlx(t_params *params);
int			close_window(t_params *params);
int			key_hook(int keysym, t_params *params);
void		process_file(char *path, t_params *params);
void		count_width_and_height(int fd, t_params *params);
void		free_params(t_params *params);
void		parse_map(int fd, t_params *params);
t_dot		*new_dot(int x, int y, int z, int c);
t_params	*params_init(void);
void		draw_map(t_params *params);
void		bresenham8(t_img *img, t_dot a, t_dot b);
void		my_pixel_put(t_img *img, int x, int y, int color);
void		isometric(t_dot *dot, double angle);
void		transform_map(t_params *params);
void		set_max_min(t_params *params, t_dot *dot);
int			get_max(int a, int b);
int			get_min(int a, int b);
void		set_offset_x_y(t_params *params);
void		set_zoom_ratio(t_params *params);
double		get_dmin(double a, double b);

#endif
