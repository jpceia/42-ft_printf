/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:53:14 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/12 20:47:51 by jceia            ###   ########.fr       */
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

int	print_string(char *s, t_spec spec)
{
	int		n_chars;
	char	*s_copy;

	if (!s)
		s = "(null)";
	s_copy = ft_strdup(s);
	if (spec.dot)
		s_copy = adjust_format_precision_str(s_copy, spec.precision);
	s_copy = adjust_format_width_space(s_copy, spec.width, spec.minus);
	ft_putstr_fd(s_copy, STDOUT_FILENO);
	n_chars = ft_strlen(s_copy);
	free(s_copy);
	return (n_chars);
}
