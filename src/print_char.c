/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:29:21 by jpceia            #+#    #+#             */
/*   Updated: 2022/01/04 21:40:17 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	append_char(char c, t_spec spec, char **out)
{
	int		width;
	char	left_whitespace;

	left_whitespace = ' ';
	if (spec.zero)
		left_whitespace = '0';
	width = spec.width;
	if (!spec.minus && width > 1)
	{
		while (--width)
			*out = ft_straddc(*out, left_whitespace);
	}
	*out = ft_straddc(*out, c);
	if (spec.minus && width > 1)
	{
		while (--width)
			*out = ft_straddc(*out, ' ');
	}
	if (spec.width > 1)
		return (spec.width);
	return (1);
}

int	append_percentage(t_spec spec, char **out)
{
	return (append_char('%', spec, out));
}
