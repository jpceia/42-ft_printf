/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:53:14 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/04 13:06:35 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

char	*adjust_format_precision_str(char *s, int len)
{
	int	n_chars;

	n_chars = ft_strlen(s);
	if (len >= 0 && len < n_chars)
		s[len] = '\0';
	return (s);
}

char	*str_arg_char(va_list *args, t_spec *spec)
{
	char	*s;
	char	c;

	(void)spec;
	s = ft_strdup(" ");
	c = (char)va_arg(*args, int);
	if (c)
		s[0] = c;
	return (adjust_format_width_space(s, spec->width, spec->minus));
}

char	*str_arg_str(va_list *args, t_spec *spec)
{
	char	*s;

	s = va_arg(*args, char *);
	if (!s)
	{
		if (spec->dot && spec->precision < 6)
			s = ft_strdup("");
		else
			s = ft_strdup("(null)");
	}
	else
	{
		s = ft_strdup(s);
		if(spec->dot)
			s = adjust_format_precision_str(s, spec->precision);
	}
	return (adjust_format_width_space(s, spec->width, spec->minus));
}
