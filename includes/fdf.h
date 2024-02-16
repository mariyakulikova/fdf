/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manya <manya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:47:12 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/16 12:07:02 by manya            ###   ########.fr       */
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

# define HEIGHT 1080
# define WIDTH 1920
# define TITLE "FdF"
# define MLX_ERROR 1

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_dot_param {
	float	x;
	float	y;
	float	z;
	int		shift_x;
	int		shift_y;
	double	angle;
}			t_coord_param;

typedef struct s_params {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
	t_list	**dot_params;
	int		map_width;
	int		map_height;
}			t_params;

int	close_window(t_params *params);
int	key_hook(int keysym, t_params *params);
int	start_window(t_params *params);
int	process_file(char *file, t_params *params);

#endif
