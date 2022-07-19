/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:27:22 by sbart             #+#    #+#             */
/*   Updated: 2021/11/13 19:52:50 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *source, size_t maxlen)
{
	size_t	res;

	res = ft_strlen(source);
	if (res < maxlen)
		ft_memcpy(dest, source, res + 1);
	else if (maxlen != 0)
	{
		ft_memcpy(dest, source, maxlen - 1);
		dest[maxlen - 1] = '\0';
	}
	return (res);
}
