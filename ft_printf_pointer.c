/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:50:40 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/04 23:22:20 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

char	*ft_ptrtoa(unsigned long nb)
{
	char	*hex;
	char	*pre;
	char	*s;

	hex = ft_lltoa_base(nb, "0123456789abcdef");
	pre = ft_strdup("0x");
	s = ft_strjoin(pre, hex);
	free(pre);
	free(hex);
	return (s);
}

int	print_pointer(va_list *args, t_spec spec)
{
	int				n_chars;
	unsigned long	nb;
	char			*s;

	nb = va_arg(*args, unsigned long);
	if (!nb)
		s = ft_strdup("(nil)");
	else
		s = ft_ptrtoa(nb);
	s = adjust_format_width_space(s, spec.width, spec.minus);
	ft_putstr_fd(s, STDOUT_FILENO);
	n_chars = ft_strlen(s);
	free(s);
	return (n_chars);
}
