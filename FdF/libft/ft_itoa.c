/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:12:58 by sbart             #+#    #+#             */
/*   Updated: 2021/11/15 18:13:02 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_c(long n)
{
	size_t	count;
	int		neg;

	count = 0;
	neg = 0;
	if (n < 0)
	{
		count++;
		neg++;
		n = -n;
	}
	while (n >= 1)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*ft_putnbr(char *res, long nbr, int count)
{
	int	neg;

	neg = 0;
	if (nbr != 0)
		res = malloc(sizeof(char) * (count + 1));
	else
		return (res = ft_strdup("0"));
	if (!res)
		return (0);
	if (nbr < 0)
	{
		neg = 1;
		nbr = -nbr;
	}
	res[count] = '\0';
	while (--count)
	{
		res[count] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (neg == 1)
		res[0] = '-';
	else
		res[0] = (nbr % 10) + '0';
	return (res);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*res;
	long	nbr;

	res = 0;
	nbr = n;
	count = ft_count_c(nbr);
	res = ft_putnbr(res, nbr, count);
	if (!res)
		return (0);
	return (res);
}
