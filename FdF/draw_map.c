/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:04:37 by sbart             #+#    #+#             */
/*   Updated: 2022/06/21 19:06:21 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 1920 || y >= 1080 || x < 0 || y < 0)
	{
		return ;
	}		
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	set_isometric(t_dots *dots, int z1, int z2, t_fdf *data)
{
	if (data->check_vision != 0)
	{
		dots->x1 = (dots->x1 - dots->y1) * cos(data->z_shift);
		dots->y1 = (dots->x1 + dots->y1) * cos(data->z_shift) - z1;
		dots->x2 = (dots->x2 - dots->y2) * cos(data->z_shift);
		dots->y2 = (dots->x2 + dots->y2) * cos(data->z_shift) - z2;
	}
}

void	alg_bresenhams(t_dots *dots, t_fdf *data)
{
	float	x_step;
	float	y_step;
	float	max;
	int		z1;
	int		z2;

	z1 = data->map[(int)dots->y1][(int)dots->x1] * data->scale;
	z2 = data->map[(int)dots->y2][(int)dots->x2] * data->scale;
	correct_position_x(dots, data);
	correct_position_y(dots, data);
	set_isometric(dots, z1, z2, data);
	set_shift_x(dots, data);
	set_shift_y(dots, data);
	x_step = dots->x2 - dots->x1;
	y_step = dots->y2 - dots->y1;
	max = find_max(x_step, y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(dots->x1 - dots->x2) || (int)(dots->y1 - dots->y2))
	{
		my_mlx_pixel_put(data, dots->x1, dots->y1, data->current_color);
		dots->x1 += x_step;
		dots->y1 += y_step;
	}
}

void	draw_row(t_fdf *data, t_dots *dots, int y)
{
	int	x;

	x = 0;
	while (x < data->count_x)
	{
		if (data->check_vision != 2)
			data->current_color = data->color[(int)y][(int)x];
		dots->x1 = x;
		dots->y1 = y;
		if (x < data->count_x - 1)
		{
			dots->x2 = x + 1;
			dots->y2 = y;
			alg_bresenhams(dots, data);
		}
		dots->x1 = x;
		dots->y1 = y;
		if (y < data->count_y - 1)
		{
			dots->x2 = x;
			dots->y2 = y + 1;
			alg_bresenhams(dots, data);
		}
		x++;
	}
}

void	draw_map(t_fdf *data)
{
	float	y;
	t_dots	*dots;

	y = 0;
	dots = (t_dots *)malloc(sizeof(t_dots));
	data->current_color = 0xffffff;
	while (y < data->count_y)
	{
		draw_row(data, dots, y);
		y++;
	}
	free(dots);
}
