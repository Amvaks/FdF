/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:36:13 by sbart             #+#    #+#             */
/*   Updated: 2021/11/13 17:21:51 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int a)
{
	if (a > 47 && a < 58)
		return (1);
	return (0);
}
