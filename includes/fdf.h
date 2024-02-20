/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:47:12 by mkulikov          #+#    #+#             */
/*   Updated: 2024/02/20 18:27:52 by mkulikov         ###   ########.fr       */
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

}			t_dot;

typedef struct s_params {
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	// t_list		*map;
	// size_t		map_width;
	// size_t		map_height;
	// t_list		*last_dot;
}			t_params;

void	start_mlx(t_params *params);
int		close_window(t_params *params);
int		key_hook(int keysym, t_params *params);
void	process_file(char *file, t_params *params);
void	ultimate_free(t_params *params);

#endif
