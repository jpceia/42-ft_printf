/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:29:21 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/09 17:45:46 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int print_char_arg(char c, va_list *args, t_spec spec)
{
	int		width;
	(void)args;

	width = spec.width;
	if (spec.minus && width > 1)
		while (--width)
			ft_putchar_fd(' ', STDOUT_FILENO);
	ft_putchar_fd(c, STDOUT_FILENO);
	if (!spec.minus && width > 1)
		while (--width)
			ft_putchar_fd(' ', STDOUT_FILENO);
	if (spec.width > 1)
		return (spec.width);
	return (1);
}

int	print_percentage(va_list *args, t_spec spec)
{
	return (print_char_arg('%', args, spec));
}

int	print_char(va_list *args, t_spec spec)
{
	char	c;

	c = (unsigned char)va_arg(*args, int);
	return (print_char_arg(c, args, spec));
}
