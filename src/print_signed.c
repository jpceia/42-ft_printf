/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:49:52 by jpceia            #+#    #+#             */
/*   Updated: 2022/01/04 21:39:01 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

char	*adjust_format_signed(char *s, t_spec spec)
{
	char	*s1;
	char	*s2;

	if (spec.precision > 0)
		s = adjust_format_precision_unsigned(s, spec.precision);
	if (spec.width && spec.zero && !spec.dot)
		s = adjust_format_precision_unsigned(s, spec.width - 1);
	s1 = ft_strdup("-");
	s2 = ft_strdup(s);
	free(s);
	s = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (adjust_format_width_space(s, spec.width, spec.minus));
}

char	*drop_left_char(char *s)
{
	char	*r;

	r = ft_strdup(s + 1);
	free(s);
	return (r);
}

int	append_signed(int nb, t_spec spec, char **out)
{
	int		n_chars;
	char	*holder;
	char	*s;

	if (spec.minus)
		spec.zero = 0;
	s = ft_lltoa(nb);
	if (nb >= 0 && !spec.plus)
		s = adjust_format_unsigned(s, spec);
	else
		s = adjust_format_signed(drop_left_char(s), spec);
	holder = *out;
	*out = ft_strjoin(holder, s);
	n_chars = ft_strlen(s);
	free(holder);
	free(s);
	return (n_chars);
}
