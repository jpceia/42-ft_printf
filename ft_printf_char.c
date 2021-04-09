/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:29:21 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/04 23:23:39 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	print_percentage(void)
{
	ft_putchar_fd('%', STDOUT_FILENO);
	return (1);
}

int	print_char(va_list *args, t_spec spec)
{
	int		width;
	char	c;

	c = (unsigned char)va_arg(*args, int);
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
