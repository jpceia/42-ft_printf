/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:53:14 by jpceia            #+#    #+#             */
/*   Updated: 2022/01/04 21:38:44 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

char	*adjust_format_precision_str(char *s, int len)
{
	int	n_chars;

	n_chars = ft_strlen(s);
	if (len >= 0 && len < n_chars)
		s[len] = '\0';
	return (s);
}

int append_string(char *s, t_spec spec, char **out)
{
	int		n_chars;
	char	*holder;
	char	*s_copy;

	if (!s)
		s = "(null)";
	s_copy = ft_strdup(s);
	if (spec.dot)
		s_copy = adjust_format_precision_str(s_copy, spec.precision);
	s_copy = adjust_format_width_space(s_copy, spec.width, spec.minus);
	holder = *out;
	*out = ft_strjoin(holder, s_copy);
	n_chars = ft_strlen(s_copy);
	free(holder);
	free(s_copy);
	return (n_chars);
}
