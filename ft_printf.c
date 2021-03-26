/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:52:33 by jpceia            #+#    #+#             */
/*   Updated: 2021/03/26 22:19:22 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_contains(char c, char *str)
{
	while (*str && c != *str)
		str++;
	return (c == *str);
}

void init_spec(t_spec *spec)
{
	spec->specifier = 0;
	spec->minus = 0;
	spec->width_value = 0;
	spec->width_star = 0;
	spec->precision = 0;
	spec->precision_value = 0;
	spec->precision_star = 0;
}

int parse_spec(const char *fmt, t_spec *spec)
{
	int index;

	if (fmt[0] != '%')
		return (-1);
	index = 1;
	while (fmt[index])
	{
		if (ft_contains(fmt[index], "cspdiuxX%%"))
		{
			spec->specifier = fmt[index];
			return (index);
		}
		else if (fmt[index] == '-')
			spec->minus = 1;
		else if (fmt[index] == '.')
			spec->precision = 1;
		else if (ft_isdigit(fmt[index]) && spec->precision)
			spec->precision_value = spec->precision_value * 10 + (fmt[index] - '0');
		else if (ft_isdigit(fmt[index]) && !spec->precision)
			spec->width_value = spec->width_value * 10 + (fmt[index] - '0');
		else if (fmt[index] == '*' && spec->precision)
			spec->precision_star = 1;
		else if (fmt[index] == '*' && !spec->precision)
			spec->width_star = 1;
		else
			return (-1);
		index++;
	}
	return (-1);
}

int print_arg(va_list *args, t_spec *spec)
{
	switch (spec->specifier)
	{
	case 'c':
		return (print_char(va_arg(*args, int), spec));
	case 's':
		return (print_str(va_arg(*args, char *), spec));
	case 'd':
	case 'i':
	case 'u':
		return (print_dec(va_arg(*args, int), spec));
	case 'x':
	case 'X':
		return (print_hex(va_arg(*args, int), spec));
	case 'p':
		return (print_ptr(va_arg(*args, void *), spec));
	case '%':
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (-1);
}

int parse_spec_width(va_list *args, t_spec *spec)
{
	if (spec->width_star)
		spec->width_value = va_arg(*args, int);
	return (0);
}

int parse_spec_precision(va_list *args, t_spec *spec)
{
	if (spec->precision_star)
		spec->precision_value = va_arg(*args, int);
	return (0);
}

int parse_spec_print_arg(const char **fmt, va_list *args)
{
	int index;
	t_spec spec;

	if (**fmt != '%')
		return (-1);
	init_spec(&spec);
	index = parse_spec(*fmt, &spec);
	*fmt = *fmt + 1;
	parse_spec_width(args, &spec);
	parse_spec_precision(args, &spec);
	if (index < 0)
		return (-1);
	*fmt = *fmt + index;
	return (print_arg(args, &spec));
}

int ft_printf(const char *fmt, ...)
{
	va_list args;
	int r;
	int ret;

	va_start(args, fmt);
	ret = 0;
	while (*fmt)
	{
		r = 1;
		if (*fmt == '%')
			r = parse_spec_print_arg(&fmt, &args);
		else
			ft_putchar_fd(*(fmt++), 1);
		if (r < 0)
			return (-1);
		ret += r;
	}
	va_end(args);
	return (ret);
}