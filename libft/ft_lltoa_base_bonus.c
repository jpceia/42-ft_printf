/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 06:30:12 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/13 17:33:10 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

static	char	*single_char_str(char *buf, char c)
{
	buf[0] = c;
	buf[1] = '\0';
	return (buf);
}

static	char	*ft_lltoa_base_core(long long nb, const char *base,
									int base_size)
{
	int		index;
	int		sign;
	char	*buf;

	buf = malloc(64);
	if (!buf)
		return (NULL);
	if (nb == 0)
		return (single_char_str(buf, base[0]));
	sign = (nb < 0);
	if (!sign)
		nb = -nb;
	index = 0;
	while (nb)
	{
		buf[index++] = base[-nb % base_size];
		nb /= base_size;
	}
	if (sign)
		buf[index++] = '-';
	buf[index] = '\0';
	return (ft_strreverse(buf));
}

char	*ft_lltoa_base(long long nb, const char *base)
{
	int		base_size;

	base_size = ft_strlen(base);
	if (base_size <= 1)
		return (NULL);
	return (ft_lltoa_base_core(nb, base, base_size));
}
