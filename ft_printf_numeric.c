/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:49:52 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/04 09:50:58 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_arg_numeric(va_list *args, t_spec *spec)
{
	char	*s;

	if (ft_contains(spec->type, "di"))
		s = ft_lltoa(va_arg(*args, int));
	else if (ft_contains(spec->type, "u"))
		s = ft_lltoa(va_arg(*args, unsigned int));
	else if (spec->type == 'x')
		s = ft_lltoa_base(va_arg(*args, int), "0123456789abcdef");
	else if (spec->type == 'X')
		s = ft_lltoa_base(va_arg(*args, int), "0123456789ABCDEF");
	return (s);
}
