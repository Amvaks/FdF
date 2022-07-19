/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:02:00 by sbart             #+#    #+#             */
/*   Updated: 2022/06/18 18:24:27 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	count_numbers(char *line, int *count_x, int *i)
{
	while (line[*i] != '\n' && line[*i] != '\0')
	{
		if (line[*i] == ' ')
		{
			*count_x = *count_x + 1;
			while (line[*i + 1] == ' ')
				*i = *i + 1;
		}
		*i = *i + 1;
	}
}

float	find_max(float x_step, float y_step)
{
	if (x_step < 0)
		x_step *= -1;
	if (y_step < 0)
		y_step *= -1;
	if (x_step > y_step)
		return (x_step);
	return (y_step);
}

int	ft_pow(int num, int pow)
{
	int	res;

	if (pow == 0)
		return (1);
	res = num;
	while (pow > 1)
	{
		res *= num;
		pow--;
	}
	return (res);
}

void	hex_to_oct(int *i, int *j, char *numb, int *res)
{
	int	pow;
	int	num;

	pow = 0;
	num = 0;
	while (*j > 0)
	{
		if (numb[*i] >= '0' && numb[*i] <= '9')
			num = numb[*i] - '0';
		else if (numb[*i] >= 'A' && numb[*i] <= 'F')
			num = numb[*i] - 'A' + 10;
		else if (numb[*i] >= 'a' && numb[*i] <= 'f')
			num = numb[*i] - 'a' + 10;
		*res = *res + (num * ft_pow(16, pow));
		*i = *i - 1;
		*j = *j - 1;
		pow++;
	}
}

int	get_color(char *numb)
{
	int	res;
	int	i;
	int	j;

	i = 0;
	j = 0;
	res = 0;
	if (ft_strchr(numb, ','))
	{
		while (numb[i] != ',')
			i++;
		i++;
		while (numb[i] && numb[i] != '\n')
		{
			i++;
			j++;
		}
		j = j - 2;
		i--;
		hex_to_oct(&i, &j, numb, &res);
		return (res);
	}
	return (0xffffff);
}
