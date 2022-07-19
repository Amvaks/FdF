/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:27:22 by sbart             #+#    #+#             */
/*   Updated: 2021/11/13 19:54:26 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *memptr, int val, size_t num)
{
	unsigned char	*dest;
	size_t			i;

	i = 0;
	dest = (unsigned char *)memptr;
	while (i < num)
	{
		dest[i] = (unsigned char)val;
		i++;
	}
	return (dest);
}
