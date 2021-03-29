/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:52:36 by jpceia            #+#    #+#             */
/*   Updated: 2021/03/29 06:40:03 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft.h"
#include "libft_bonus.h"
#include <stdarg.h>

typedef struct s_spec
{
	char specifier;
	char minus;
	char zero;
	char width;
	char width_star;
	char dot;
	char precision;
	char precision_star;
} t_spec;

int ft_printf(const char *, ...);
char *ft_ptrtoa(void *ptr);

#endif