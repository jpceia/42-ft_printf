/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:52:33 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/12 20:39:37 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include "ft_printf.h"

int	print_arg(va_list *args, t_spec spec)
{
	if (spec.type == 'c')
		return (print_char(va_arg(*args, int), spec));
	if (spec.type == 's')
		return (print_string(va_arg(*args, char *), spec));
	if (ft_contains(spec.type, "di"))
		return (print_signed(va_arg(*args, int), spec));
	if (ft_contains(spec.type, "uxX"))
		return (print_unsigned(va_arg(*args, unsigned int), spec));
	if (spec.type == 'p')
		return (print_pointer(va_arg(*args, void *), spec));
	if (spec.type == '%')
		return (print_percentage(spec));
	return (PFT_ERR);
}

int	parse_and_print_item(const char **fmt, va_list *args)
{
	int		index;
	t_spec	spec;

	if (**fmt != '%')
		return (-1);
	index = parse_spec(*fmt, &spec);
	parse_spec_star(args, &spec);
	if (index < 0)
		return (PFT_ERR);
	*fmt = *fmt + index + 1;
	return (print_arg(args, spec));
}

int	ft_vprintf(const char *fmt, va_list args)
{
	va_list	args_copy;
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
			ft_putchar_fd(*(fmt++), STDOUT_FILENO);
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
