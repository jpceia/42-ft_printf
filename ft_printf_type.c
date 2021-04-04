/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:50:40 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/04 09:50:50 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ptrtoa(void *ptr)
{
	char	*hex;
	char	*out;

	if (!ptr)
		return (ft_strdup("(nil)"));
	hex = ft_lltoa_base((unsigned long)ptr, "0123456789abcdef");
	out = ft_strjoin("0x", hex);
	free(hex);
	return (out);
}
