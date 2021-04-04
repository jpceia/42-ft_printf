/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:52:33 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/04 09:53:04 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(va_list *args, t_spec *spec)
{
	int		n_chars;
	char	*s;
	char	c;

	if (spec->type == 'c')
		s = str_arg_c(args, spec);
	else if (spec->type == 's')
		s = str_arg_str(args, spec);
	else if (ft_contains(spec->type, "diuxX"))
		s = str_arg_numeric(args, spec);
	else if (spec->type == 'p')
		s = ft_ptrtoa(va_arg(*args, void *));
	else if (spec->type == '%')
		s = ft_strdup("\%");
	else
		return (PFT_ERR);
	n_chars = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (n_chars);
}

int	parse_spec_star(va_list *args, t_spec *spec)
{
	if (spec->width_star)
		spec->width = va_arg(*args, int);
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

int	parse_and_print_item(const char **fmt, va_list *args)
{
	int		index;
	t_spec	spec;

	if (**fmt != '%')
		return (-1);
	init_spec(&spec);
	index = parse_spec(*fmt, &spec);
	*fmt = *fmt + 1;
	parse_spec_star(args, &spec);
	if (index < 0)
		return (-1);
	*fmt = *fmt + index;
	return (print_arg(args, &spec));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		r;
	int		ret;

	va_start(args, fmt);
	ret = 0;
	while (*fmt)
	{
		r = 1;
		if (*fmt == '%')
			r = parse_and_print_item(&fmt, &args);
		else
			ft_putchar_fd(*(fmt++), 1);
		if (r < 0)
			return (-1);
		ret += r;
	}
	va_end(args);
	return (ret);
}
