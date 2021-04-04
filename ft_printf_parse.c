/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:30:54 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/04 09:33:46 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_spec(t_spec *spec)
{
	spec->type = 0;
	spec->minus = 0;
	spec->width = 0;
	spec->width_star = 0;
	spec->dot = 0;
	spec->precision = 0;
	spec->precision_star = 0;
}

int	parse_spec_loop(char c, t_spec *spec)
{
	if (!c)
		return (PFT_ERR);
	else if (ft_contains(c, "cspdiuxX%%"))
	{
		spec->type = c;
		return (PFT_STOP);
	}
	else if (c == '-')
		spec->minus = 1;
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