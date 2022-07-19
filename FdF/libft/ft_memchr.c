/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:24:26 by sbart             #+#    #+#             */
/*   Updated: 2021/11/13 19:55:09 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memptr, int val, size_t num)
{
	unsigned char	*res;

	res = (unsigned char *)memptr;
	if (num == 0)
		return (NULL);
	while (num--)
	{
		if (*res == (unsigned char)val)
			return (res);
		res++;
	}
	return (NULL);
}
