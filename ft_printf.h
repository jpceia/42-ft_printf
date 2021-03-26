/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:52:36 by jpceia            #+#    #+#             */
/*   Updated: 2021/03/26 22:19:20 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft.h"
#include <stdarg.h>

typedef struct s_spec
{
	char specifier;
	char minus;
	char zero;
	char width_value;
	char width_star;
	char precision;
	char precision_value;
	char precision_star;
} t_spec;

int ft_printf(const char *, ...);

int print_hex(long long n, t_spec *spec);
int print_dec(long long n, t_spec *spec);
int print_ptr(void *ptr, t_spec *spec);
int print_char(char c, t_spec *spec);
int print_whitespace(int len);
int print_str(char *s, t_spec *spec);
int print_nbr(int nb, t_spec *spec);

#endif