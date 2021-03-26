/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:52:33 by jpceia            #+#    #+#             */
/*   Updated: 2021/03/26 19:49:13 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct s_spec
{
	char specifier;
	char minus;
	char zero;
	char width;
	char width_star;
	char precision;
	char precision_nb;
	char precision_star;
} t_spec;

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
	spec->width = 0;
	spec->width_star = 0;
	spec->precision = 0;
	spec->precision_nb = 0;
	spec->precision_star = 0;
}

int parse_spec(const char *fmt, t_spec *spec)
{
	int index;

	if (fmt[0] != '%')
		return (-1);
	init_spec(spec);
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
			spec->precision_nb = spec->precision_nb * 10 + (fmt[index] - '0');
		else if (ft_isdigit(fmt[index]) && !spec->precision)
			spec->width = spec->width * 10 + (fmt[index] - '0');
		else if (fmt[index] == '*' && spec->precision)
			spec->precision_star = 1;
		else if (fmt[index] == '*' && !spec->precision)
			spec->width_star = 1;
		else
			break;
		index++;
	}
	return (-1);
}

int print_arg(t_spec spec, va_list *args)
{
	char *s;

	switch (spec.specifier)
	{
	case 'c':
		ft_putchar_fd(va_arg(*args, int), 0);
		return (1);
	case 's':
		s = va_arg(*args, char *);
		ft_putstr_fd(s, 0);
		return (ft_strlen(s));
	case 'd':
	case 'i':
		ft_putnbr_fd(va_arg(*args, int), 1);
		return (1); // to change
	case '%':
		ft_putchar_fd('%', 0);
		return (1);
	}
	return (-1);
}

int parse_spec_print_arg(const char **fmt, va_list *args)
{
	int index;
	t_spec spec;

	if (**fmt != '%')
		return (-1);
	index = parse_spec(*fmt, &spec);
	if (index < 0)
		return (-1);
	*fmt = *fmt + index;
	return (print_arg(spec, args));
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
			ft_putchar_fd(*(fmt++), 0);
		if (r < 0)
		{
			ret = r;
			break;
		}
		ret += r;
	}
	va_end(args);
	return (-1);
}