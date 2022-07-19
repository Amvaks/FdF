/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:33:45 by sbart             #+#    #+#             */
/*   Updated: 2022/06/17 16:13:14 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	correct_position_y(t_dots *dots, t_fdf *data)
{
	dots->y1 *= data->zoom;
	dots->y2 *= data->zoom;
	if (data->check_vision == 1 || data->check_vision == 2)
	{
		dots->y1 -= 650;
		dots->y2 -= 650;
	}
	else
	{
		dots->y1 += 50;
		dots->y2 += 50;
	}
}

void	correct_position_x(t_dots *dots, t_fdf *data)
{
	dots->x1 = dots->x1 * data->zoom;
	dots->x2 = dots->x2 * data->zoom;
	if (data->check_vision == 1 || data->check_vision == 2)
	{
		dots->x1 = dots->x1 + 750;
		dots->x2 = dots->x2 + 750;
	}
	else
	{
		dots->x1 = dots->x1 + 530;
		dots->x2 = dots->x2 + 530;
	}
}

void	set_shift_x(t_dots *dots, t_fdf *data)
{
	dots->x1 = dots->x1 + data->x_shift;
	dots->x2 = dots->x2 + data->x_shift;
}

void	set_shift_y(t_dots *dots, t_fdf *data)
{
	dots->y1 = dots->y1 + data->y_shift;
	dots->y2 = dots->y2 + data->y_shift;
}
