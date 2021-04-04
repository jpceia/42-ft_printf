/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:50:40 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/04 13:22:00 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

char	*ft_ptrtoa(unsigned long nb)
{
	char	*hex;
	char    *pre;
	char	*s;

	hex = ft_lltoa_base(nb, "0123456789abcdef");
	pre = ft_strdup("0x");
	s = ft_strjoin(pre, hex);
	free(pre);
	free(hex);
	return (s);
}

char	*str_arg_pointer(va_list *args, t_spec *spec)
{
	unsigned long	nb;
	char 			*s;

	nb = va_arg(*args, unsigned long);
	if (!nb)
		s = ft_strdup("(nil)");
	else
		s = ft_ptrtoa(nb);
	return (adjust_format_width_space(s, spec->width, spec->minus));
}