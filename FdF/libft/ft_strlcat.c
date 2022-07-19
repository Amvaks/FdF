/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:27:22 by sbart             #+#    #+#             */
/*   Updated: 2021/11/13 19:52:58 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *source, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(dest);
	if (size < len)
		return (ft_strlen(source) + size);
	while (source[i] && (len + i + 1) < size)
	{
		dest[len + i] = ((char *)source)[i];
		i++;
	}
	dest[len + i] = '\0';
	return (len + ft_strlen(source));
}
