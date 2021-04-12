/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:53:14 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/12 20:31:32 by jceia            ###   ########.fr       */
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

int	print_string(va_list *args, t_spec spec)
{
	int		n_chars;
	char	*s;

	s = va_arg(*args, char *);
	if (!s)
		s = "(null)";
	s = ft_strdup(s);
	if (spec.dot)
		s = adjust_format_precision_str(s, spec.precision);
	s = adjust_format_width_space(s, spec.width, spec.minus);
	ft_putstr_fd(s, STDOUT_FILENO);
	n_chars = ft_strlen(s);
	free(s);
	return (n_chars);
}