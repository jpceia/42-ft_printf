/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:52:33 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/04 21:26:42 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"
#include "ft_printf.h"

int	print_arg(va_list *args, t_spec *spec)
{
	int		n_chars;
	char	*s;

	if (spec->type == 'c')
		s = str_arg_char(args, spec);
	else if (spec->type == 's')
		s = str_arg_str(args, spec);
	else if (ft_contains(spec->type, "di"))
		s = str_arg_signed(args, spec);
	else if (ft_contains(spec->type, "uxX"))
		s = str_arg_unsigned(args, spec);
	else if (spec->type == 'p')
		s = str_arg_pointer(args, spec);
	else if (spec->type == '%')
		s = ft_strdup("\%");
	else
		return (PFT_ERR);
	n_chars = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (n_chars);
}

int	parse_and_print_item(const char **fmt, va_list *args)
{
	int		index;
	t_spec	spec;

	if (**fmt != '%')
		return (-1);
	init_spec(&spec);
	index = parse_spec(*fmt, &spec);
	parse_spec_star(args, &spec);
	if (index < 0)
		return (PFT_ERR);
	*fmt = *fmt + index + 1;
	return (print_arg(args, &spec));
}

int ft_vprintf(const char *fmt, va_list args)
{
	va_list args_copy;
	int		n;
	int		i;

	n = 0;
	va_copy(args_copy, args);
	while (*fmt)
	{
		i = 1;
		if (*fmt == '%')
			i = parse_and_print_item(&fmt, &args_copy);
		else
			ft_putchar_fd(*(fmt++), 1);
		if (i < 0)
			return (PFT_ERR);
		n += i;
	}
	return (n);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		n;

	va_start(args, fmt);
	n = ft_vprintf(fmt, args);
	va_end(args);
	return (n);
}
