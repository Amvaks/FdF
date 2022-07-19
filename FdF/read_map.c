/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:52:11 by sbart             #+#    #+#             */
/*   Updated: 2022/06/18 19:22:52 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_x(char *map_name)
{
	char	*line;
	int		i;
	int		count_x;
	int		fd;

	count_x = 0;
	i = 0;
	fd = open(map_name, O_RDONLY, 0);
	line = get_next_line(fd);
	if (line[0] == ' ')
		i++;
	count_numbers(line, &count_x, &i);
	if (line[i - 1] != ' ')
		count_x++;
	free(line);
	close(fd);
	return (count_x);
}

int	get_y(char *map_name)
{
	char	*line;
	int		count_y;
	int		fd;

	count_y = 0;
	fd = open(map_name, O_RDONLY, 0);
	line = get_next_line(fd);
	while (line && (line[0] != '\n' || line[0] != '\0'))
	{
		free(line);
		line = get_next_line(fd);
		count_y++;
	}
	free(line);
	close(fd);
	return (count_y);
}

void	set_matrix(int *z_line, char *line, int *color)
{
	char	**numb;
	int		i;

	numb = ft_split(line, ' ');
	i = 0;
	while (numb[i])
	{
		color[i] = get_color(numb[i]);
		z_line[i] = ft_atoi(numb[i]);
		free(numb[i]);
		i++;
	}
	free(numb);
}

void	set_memory(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->count_y)
	{
		data->map[i] = (int *)malloc(sizeof(int) * (data->count_x + 1));
		data->color[i] = (int *)malloc(sizeof(int) * (data->count_x + 1));
		i++;
	}
}

void	read_map(char *map_name, t_fdf *data)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	data->count_x = get_x(map_name);
	data->count_y = get_y(map_name);
	data->map = (int **)malloc(sizeof(int *) * (data->count_y + 1));
	data->color = (int **)malloc(sizeof(int *) * (data->count_y + 1));
	set_memory(data);
	fd = open(map_name, O_RDONLY, 0);
	line = get_next_line(fd);
	while (i < data->count_y)
	{
		set_matrix(data->map[i], line, data->color[i]);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	data->map[i] = NULL;
	close(fd);
}
