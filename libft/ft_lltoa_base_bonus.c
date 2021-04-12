/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 06:30:12 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/12 16:46:45 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

static	char	*single_char_str(char *buf, char c)
{
	buf[0] = '0';
	buf[1] = '\0';
	return (buf);
}

char	*ft_lltoa_base(long long nb, const char *base)
{
	int		base_size;
	int		index;
	int		sign;
	char	*buf;

	base_size = ft_strlen(base);
	if (base_size <= 1)
		return (NULL);
	buf = malloc(64);
	if (!buf)
		return (NULL);
	if (nb == 0)
		return (*single_char_str(buf, base[0]));
	index = 63;
	buf[index--] = '\0';
	sign = (nb < 0);
	if (!sign)
		nb = -nb;
	while (nb && index)
	{
		buf[index--] = base[-nb % base_size];
		nb /= base_size;
	}
	if (sign)
		buf[index--] = '-';
	return (ft_memmove(buf, &buf[index + 1], 63 - index));
}
