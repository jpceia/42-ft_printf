/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:52:33 by jpceia            #+#    #+#             */
/*   Updated: 2022/01/04 21:36:13 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include "ft_printf.h"

int	append_arg(va_list *args, t_spec spec, char **out)
{
	if (spec.type == 'c')
		return (append_char(va_arg(*args, int), spec, out));
	if (spec.type == 's')
		return (append_string(va_arg(*args, char *), spec, out));
	if (ft_contains(spec.type, "di"))
		return (append_signed(va_arg(*args, int), spec, out));
	if (ft_contains(spec.type, "uxX"))
		return (append_unsigned(va_arg(*args, unsigned int), spec, out));
	if (spec.type == 'p')
		return (append_pointer(va_arg(*args, void *), spec, out));
	if (spec.type == '%')
		return (append_percentage(spec, out));
	return (PFT_ERR);
}

int	parse_and_append(const char **fmt, va_list *args, char **out)
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
	return (append_arg(args, spec, out));
}

int	ft_vprintf(const char *fmt, va_list args)
{
	va_list	args_copy;
	char	*str;
	int		n;
	int		i;

	n = 0;
	va_copy(args_copy, args);
	str = ft_strdup("");
	while (*fmt)
	{
		i = 1;
		if (*fmt == '%')
			i = parse_and_append(&fmt, &args_copy, &str);
		else
			str = ft_straddc(str, *(fmt++));
		if (i < 0)
			return (PFT_ERR);
		n += i;
	}
	ft_putstr_fd(str, STDOUT_FILENO);
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
