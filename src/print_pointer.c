/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:50:40 by jpceia            #+#    #+#             */
/*   Updated: 2022/01/04 21:39:16 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

char	*ft_ptrtoa(void *ptr)
{
	char	*hex;
	char	*pre;
	char	*s;

	hex = ft_ulltoa_base((unsigned long long)ptr, "0123456789abcdef");
	pre = ft_strdup("0x");
	s = ft_strjoin(pre, hex);
	free(pre);
	free(hex);
	return (s);
}

int	append_pointer(void *ptr, t_spec spec, char **out)
{
	int		n_chars;
	char	*holder;
	char	*s;

	if (!ptr)
		s = ft_strdup("0x0");
	else
		s = ft_ptrtoa(ptr);
	s = adjust_format_width_space(s, spec.width, spec.minus);
	holder = *out;
	*out = ft_strjoin(holder, s);
	n_chars = ft_strlen(s);
	free(holder);
	free(s);
	return (n_chars);
}
