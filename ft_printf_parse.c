/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:30:54 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/04 23:31:11 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	init_spec(t_spec *spec)
{
	spec->type = 0;
	spec->minus = 0;
	spec->plus = 0;
	spec->space = 0;
	spec->hash = 0;
	spec->zero = 0;
	spec->width = 0;
	spec->width_star = 0;
	spec->dot = 0;
	spec->precision = 0;
	spec->precision_star = 0;
}

int	parse_flag(char c, t_spec *spec)
{
	if (c == '-')
		spec->minus = 1;
	else if (c == '+')
		spec->plus = 1;
	else if (c == '#')
		spec->hash = 1;
	else if (c == ' ')
		spec->space = 1;
	return (PFT_CONTINUE);
}

int	parse_spec_loop(char c, t_spec *spec)
{
	if (ft_contains(c, "cspdiuxX%%"))
	{
		spec->type = c;
		return (PFT_STOP);
	}
	else if (ft_contains(c, "-+ #"))
		parse_flag(c, spec);
	else if (c == '.')
		spec->dot = 1;
	else if (c == '0' && !spec->dot && !spec->width)
		spec->zero = 1;
	else if (ft_isdigit(c) && spec->dot)
		spec->precision = spec->precision * 10 + (c - '0');
	else if (ft_isdigit(c) && !spec->dot)
		spec->width = spec->width * 10 + (c - '0');
	else if (c == '*' && spec->dot)
		spec->precision_star = 1;
	else if (c == '*' && !spec->dot)
		spec->width_star = 1;
	else
		return (PFT_ERR);
	return (PFT_CONTINUE);
}

int	parse_spec(const char *fmt, t_spec *spec)
{
	int	index;
	int	status;

	init_spec(spec);
	index = 0;
	status = PFT_CONTINUE;
	if (fmt[index] != '%')
		return (PFT_ERR);
	while (status == PFT_CONTINUE)
		status = parse_spec_loop(fmt[++index], spec);
	if (status == PFT_STOP)
		return (index);
	return (PFT_ERR);
}

int	parse_spec_star(va_list *args, t_spec *spec)
{
	if (spec->width_star)
	{
		spec->width = va_arg(*args, int);
		if (spec->width < 0)
		{
			spec->minus = 1;
			spec->width = -spec->width;
		}
	}
	if (spec->precision_star)
	{
		spec->precision = va_arg(*args, int);
		if (spec->precision < 0)
		{
			spec->dot = 0;
			spec->precision = 0;
		}
	}
	return (0);
}
