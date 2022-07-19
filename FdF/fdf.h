/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:47:02 by sbart             #+#    #+#             */
/*   Updated: 2022/06/19 15:54:40 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"

typedef struct s_fdf
{
	float	zoom;
	float	scale;
	int		check_vision;
	int		count_x;
	int		count_y;
	int		x_shift;
	int		y_shift;
	float	z_shift;
	int		current_color;
	int		**map;
	int		**color;

	int		bits_per_pixel;
	int		line_length;
	int		endian;

	void	*mlx_ptr;
	void	*win_ptr;

	void	*img;
	char	*addr;
}			t_fdf;

typedef struct s_dot
{
	float	x1;
	float	x2;
	float	y1;
	float	y2;
}			t_dots;

void	read_map(char *map_name, t_fdf *data);
void	alg_bresenhams(t_dots *dots, t_fdf *data);
void	draw_map(t_fdf *data);
int		get_color(char *numb);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
float	find_max(float x_step, float y_step);
void	correct_position_x(t_dots *dots, t_fdf *data);
void	correct_position_y(t_dots *dots, t_fdf *data);
void	set_shift_x(t_dots *dots, t_fdf *data);
void	set_shift_y(t_dots *dots, t_fdf *data);
void	count_numbers(char *line, int *count_x, int *i);
int		clean_memory(t_fdf *data);
void	check_error(int argc, char **argv);

#endif