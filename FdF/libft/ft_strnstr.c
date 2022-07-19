/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:27:22 by sbart             #+#    #+#             */
/*   Updated: 2021/11/13 19:52:01 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	num;

	i = 0;
	if (*little == 0)
		return ((char *)big);
	while (big[i] && len > i)
	{
		num = 0;
		while (big[i + num] == little[num] && i + num < len)
		{
			num++;
			if (little[num] == 0)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
