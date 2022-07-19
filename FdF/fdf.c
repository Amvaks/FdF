/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:47:05 by sbart             #+#    #+#             */
/*   Updated: 2022/06/21 19:07:50 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_zoom(int key, t_fdf *data)
{
	int	size;

	size = data->count_x + data->count_y;
	if (key == 27 && size < 80)
	{
		if ((data->zoom - 8) > 0.6)
			data->zoom -= 8;
	}
	else if (key == 27 && size < 410)
	{
		if ((data->zoom - 1) > 0.4)
			data->zoom -= 1;
	}
	else if (key == 27 && size >= 410)
	{
		if ((data->zoom - 0.2) > 0.2)
			data->zoom -= 0.2;
	}
	else if (key == 24 && size < 80)
		data->zoom += 8;
	else if (key == 24 && size < 410)
		data->zoom += 1;
	else if (key == 24 && size >= 410)
		data->zoom += 0.2;
}

void	change_scale(int key, t_fdf *data)
{
	float	scale_down;
	float	scale_up;

	scale_down = data->scale / 1.5;
	scale_up = 0;
	if (data->scale < 100 && data->count_x < 150)
		scale_up = 1;
	else if (data->scale < 20 && data->count_x > 150)
		scale_up = 1;
	if (key == 12 && scale_down != 0 && data->count_x < 150)
		data->scale /= 1.5;
	else if (key == 12 && scale_down != 0)
		data->scale /= 1.2;
	else if (key == 14 && scale_up == 1 && data->count_x < 150)
		data->scale *= 1.5;
	else if (key == 14 && scale_up == 1)
		data->scale *= 1.2;
	else if (key == 7)
		data->z_shift -= 0.05;
	else if (key == 6)
		data->z_shift += 0.05;
}

void	change_vision(int key, t_fdf *data)
{
	if (key == 19)
		data->check_vision = 0;
	else if (key == 18)
		data->check_vision = 1;
	else if (key == 20)
		data->check_vision = 2;
}

int	deal_key(int key, t_fdf *data)
{
	if (key == 126 || key == 13)
		data->y_shift -= 25;
	else if (key == 125 || key == 1)
		data->y_shift += 25;
	else if (key == 123 || key == 0)
		data->x_shift -= 25;
	else if (key == 124 || key == 2)
		data->x_shift += 25;
	else if (key == 24 || key == 27)
		change_zoom(key, data);
	else if (key == 18 || key == 19 || key == 20)
		change_vision(key, data);
	else if (key == 6 || key == 7 || key == 12 || key == 14)
		change_scale(key, data);
	else if (key == 53)
		clean_memory(data);
	else
		return (0);
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	draw_map(data);
	mlx_put_image_to_window(&data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	check_error(argc, argv);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	data->zoom = 22;
	data->check_vision = 1;
	data->scale = 1;
	data->x_shift = 0;
	data->y_shift = 0;
	data->z_shift = 0.8;
	read_map(argv[1], data);
	if (data->count_x > data->count_y)
		data->zoom = 1200 / data->count_x;
	else
		data->zoom = 1200 / data->count_y;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "FDF");
	data->img = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	draw_map(data);
	mlx_put_image_to_window(&data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, clean_memory, data);
	mlx_loop(data->mlx_ptr);
}
