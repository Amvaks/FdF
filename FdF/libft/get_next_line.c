/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:33:54 by sbart             #+#    #+#             */
/*   Updated: 2021/12/21 13:34:49 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_line(int fd, char *buff, char *remainder)
{
	int		bytes_r;
	char	*tmp;

	bytes_r = 1;
	if (!remainder)
		remainder = ft_strdup("");
	if (!remainder)
		return (0);
	while (!ft_strchr(remainder, '\n') && bytes_r)
	{
		bytes_r = read(fd, buff, BUFFER_SIZE);
		if (bytes_r < 0)
		{
			free(remainder);
			return (0);
		}
		buff[bytes_r] = '\0';
		tmp = remainder;
		remainder = ft_strjoin(remainder, buff);
		free(tmp);
		if (!remainder)
			return (0);
	}	
	return (remainder);
}

char	*ft_get_remaind(char *remainder)
{
	char	*res;
	int		i;

	i = 0;
	if (!remainder)
		return (0);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\0')
	{
		free(remainder);
		return (0);
	}
	res = (char *) malloc(sizeof(char) * (ft_strlen(remainder) - i + 1));
	if (!res)
	{
		free(remainder);
		return (0);
	}
	ft_strlcpy(res, remainder + i + 1, ft_strlen(remainder) - i + 1);
	free(remainder);
	return (res);
}

char	*ft_cut_line(char	*remainder)
{
	char	*res;
	int		i;

	i = 0;
	if (!remainder)
		return (0);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (0);
	ft_strlcpy(res, remainder, i + 2);
	if (!res[0])
	{
		free(res);
		return (0);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*remainder;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	remainder = get_line(fd, buff, remainder);
	free (buff);
	res = ft_cut_line(remainder);
	remainder = ft_get_remaind(remainder);
	return (res);
}
