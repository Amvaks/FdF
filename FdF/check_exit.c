/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:40:29 by sbart             #+#    #+#             */
/*   Updated: 2022/06/19 15:58:34 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_error(int argc, char **argv)
{
	if (argc != 2 || access(argv[1], F_OK) != 0 || access(argv[1], R_OK) != 0)
	{
		write(1, "Please enter one correct map!\n", 30);
		exit(1);
	}
}

int	clean_memory(t_fdf *data)
{
	int	i;

	i = 0;
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img);
	while (i < data->count_y)
	{
		free(data->map[i]);
		free(data->color[i]);
		i++;
	}
	free(data->map);
	free(data->color);
	free(data);
	exit(0);
	return (0);
}
