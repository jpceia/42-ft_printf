/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:52:33 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/04 09:34:27 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	prec_adjust(char **s, t_spec *spec)
{
	int		n_chars;
	char	*holder;

	if (spec->dot)
	{
		if (spec->type == 's')
		{
			if (!*s)
			{
				if (spec->precision < 6)
					*s = ft_strdup("");
				else
					*s = ft_strdup("(null)");
				return ;
			}
			if (spec->precision < (char)ft_strlen(*s))
			{
				holder = *s;
				*s = ft_substr(holder, 0, spec->precision);
				free(holder);
			}
		}
		else if (ft_contains(spec->type, "diuoxX"))
		{
			n_chars = ft_strlen(*s);
			if (spec->precision > n_chars)
			{
				holder = *s;
				*s = malloc(spec->precision);
				ft_memset(*s, '0', spec->precision);
				ft_memcpy(*s + spec->precision - n_chars, holder, n_chars);
				free(holder);
			}
		}
	}
}

void	width_adjust(char **s, t_spec *spec)
{
	char	*holder;
	int		n_chars;
	int		padding;
	char	pad_char;

	padding = 0;
	if (!*s && spec->type == 's')
		*s = ft_strdup("(null)");
	n_chars = ft_strlen(*s);
	pad_char = ' ';
	if (spec->width > n_chars && spec->type != '%')
	{
		holder = *s;
		*s = malloc(spec->width);
		ft_memset(*s, pad_char, spec->width);
		if (!spec->minus)
			padding = spec->width - n_chars;
		ft_memcpy(*s + padding, holder, n_chars);
		free(holder);
	}
}

int	print_arg(va_list *args, t_spec *spec)
{
	int		n_chars;
	char	*s;
	char	c;

	if (spec->type == 'c')
	{
		c = (char)va_arg(*args, int);
		s = malloc(2);
		if (!s)
			return (-1);
		s[0] = c;
		s[1] = '\0';
	}
	else if (spec->type == 's')
	{
		s = va_arg(*args, char *);
		s = ft_strdup(s);
	}
	else if (ft_contains(spec->type, "di"))
		s = ft_lltoa(va_arg(*args, int));
	else if (ft_contains(spec->type, "u"))
		s = ft_lltoa(va_arg(*args, unsigned int));
	else if (spec->type == 'x')
		s = ft_lltoa_base(va_arg(*args, int), "0123456789abcdef");
	else if (spec->type == 'X')
		s = ft_lltoa_base(va_arg(*args, int), "0123456789ABCDEF");
	else if (spec->type == 'p')
		s = ft_ptrtoa(va_arg(*args, void *));
	else if (spec->type == '%')
		s = ft_strdup("\%");
	else
		return (-1);
	prec_adjust(&s, spec);
	width_adjust(&s, spec);
	n_chars = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (n_chars);
}

int	parse_spec_width(va_list *args, t_spec *spec)
{
	if (spec->width_star)
		spec->width = va_arg(*args, int);
	return (0);
}

int	parse_spec_precision(va_list *args, t_spec *spec)
{
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

int	parse_spec_print_arg(const char **fmt, va_list *args)
{
	int		index;
	t_spec	spec;

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
