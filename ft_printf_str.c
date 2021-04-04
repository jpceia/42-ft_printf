/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:53:14 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/04 09:53:27 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_arg_char(va_list *args, t_spec *spec)
{
	s = ft_strdup(" ");
	c = (char)va_arg(*args, int);
	if (c)
		s[0] = c;
	return (s);
}

char	*str_arg_str(va_list *args, t_spec *spec)
{
	char	*s;

	s = va_arg(*args, char *);
	s = ft_strdup(s);
	return (s);
}
