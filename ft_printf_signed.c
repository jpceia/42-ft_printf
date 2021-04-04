/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_signed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:49:52 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/04 22:02:11 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static char *adjust_format_negative(char *s, t_spec spec)
{
	char	*s1;
	char	*s2;

	if (spec.precision > 0)
		s = adjust_format_precision_unsigned(s, spec.precision);
	if (spec.width && spec.zero && spec.precision <= 0)
		s = adjust_format_precision_unsigned(s, spec.width - 1);
	s1 = ft_strdup("-");
	s2 = ft_strdup(s);
	s = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (adjust_format_width_space(s, spec.width, spec.minus));
}

int		print_signed(va_list *args, t_spec spec)
{
	long	nb;
	char	*s;
	
	nb = va_arg(*args, int);
	if (nb >= 0)
		s = adjust_format_unsigned(ft_lltoa(nb), spec);
	else
		s = adjust_format_negative(ft_lltoa(-nb), spec);
	ft_putstr_fd(s, STDOUT_FILENO);
	return (ft_strlen(s));
}
