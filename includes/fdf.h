/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:47:12 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/14 15:01:53 by mkulikov         ###   ########.fr       */
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
# include "../libft/libft.h"
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

typedef struct s_vars {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
}				t_vars;

int		close_window(t_vars *vars);
int		key_hook(int keysym, t_vars *vars);
int		start_window(t_vars *vars);

#endif
