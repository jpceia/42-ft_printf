/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:50:40 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/12 20:31:21 by jceia            ###   ########.fr       */
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

int	print_pointer(va_list *args, t_spec spec)
{
	int		n_chars;
	void	*ptr;
	char	*s;

	ptr = va_arg(*args, void *);
	if (!ptr)
		s = ft_strdup("0x0");
	else
		s = ft_ptrtoa(ptr);
	s = adjust_format_width_space(s, spec.width, spec.minus);
	ft_putstr_fd(s, STDOUT_FILENO);
	n_chars = ft_strlen(s);
	free(s);
	return (n_chars);
}
