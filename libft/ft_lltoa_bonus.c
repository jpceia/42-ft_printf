/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 06:08:23 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/09 17:55:35 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

char	*ft_lltoa(long long nb)
{
	int		index;
	int		sign;
	char	*buf;

	buf = malloc(21);
	if (!buf)
		return (NULL);
	if (nb == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return (buf);
	}
	index = 20;
	buf[index--] = '\0';
	sign = (nb < 0);
	if (!sign)
		nb = -nb;
	while (nb && index)
	{
		buf[index--] = '0' - nb % 10;
		nb /= 10;
	}
	if (sign)
		buf[index--] = '-';
	return (ft_memmove(buf, &buf[index + 1], 20 - index));
}
