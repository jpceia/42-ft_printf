/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:49:52 by jpceia            #+#    #+#             */
/*   Updated: 2022/01/04 21:38:39 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

char	*adjust_format_precision_unsigned(char *s, size_t n_digits)
{
	size_t	n_chars;
	size_t	len;
	char	*s1;
	char	*s2;

	n_chars = ft_strlen(s);
	if (n_chars < n_digits)
	{
		len = (int)n_digits - (int)n_chars;
		s1 = malloc(len + 1);
		ft_memset(s1, '0', len);
		s1[len] = '\0';
		s2 = ft_strdup(s);
		free(s);
		s = ft_strjoin(s1, s2);
		free(s1);
		free(s2);
	}
	return (s);
}

char	*add_left_char(char *s, char c)
{
	size_t	len;
	char	*out;

	len = ft_strlen(s);
	out = malloc(len + 2);
	out[len + 1] = '\0';
	out[0] = c;
	ft_memcpy(out + 1, s, len);
	free(s);
	return (out);
}

char	*adjust_format_unsigned(char *s, t_spec spec)
{
	if (spec.precision > 0)
		s = adjust_format_precision_unsigned(s, spec.precision);
	else if (spec.dot && spec.precision == 0 && *s == '0')
	{
		free(s);
		s = ft_strdup("");
	}
	if (spec.width && spec.zero && !spec.dot && !spec.minus)
		s = adjust_format_precision_unsigned(s, spec.width);
	if (spec.space && !spec.plus)
		s = add_left_char(s, ' ');
	return (adjust_format_width_space(s, spec.width, spec.minus));
}

int	append_unsigned(unsigned int nb, t_spec spec, char **out)
{
	int		n_chars;
	char	*holder;
	char	*s;

	s = NULL;
	if (ft_contains(spec.type, "u"))
		s = ft_ulltoa(nb);
	else if (spec.type == 'x')
	{
		s = ft_ulltoa_base(nb, "0123456789abcdef");
		if (spec.hash)
			s = add_left_char(add_left_char(s, 'x'), '0');
	}
	else if (spec.type == 'X')
	{
		s = ft_ulltoa_base(nb, "0123456789ABCDEF");
		if (spec.hash)
			s = add_left_char(add_left_char(s, 'X'), '0');
	}
	else
		return (PFT_ERR);
	s = adjust_format_unsigned(s, spec);
	holder = *out;
	*out = ft_strjoin(holder, s);
	n_chars = ft_strlen(s);
	free(holder);
	free(s);
	return (n_chars);
}
