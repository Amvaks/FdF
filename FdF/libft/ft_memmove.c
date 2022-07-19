/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:27:22 by sbart             #+#    #+#             */
/*   Updated: 2021/11/13 19:54:35 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t num)
{
	unsigned char	*dst;
	unsigned char	*src;

	if (!dest && !source)
		return (NULL);
	dst = (unsigned char *)dest;
	src = (unsigned char *)source;
	if (src < dst)
		while (num--)
			dst[num] = src[num];
	else
		ft_memcpy(dest, source, num);
	return (dest);
}
