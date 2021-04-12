/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:47:33 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/12 20:32:03 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# define PFT_ERR		-1
# define PFT_STOP	 	 0
# define PFT_CONTINUE	 1

# include <stdarg.h>
# include "libft.h"
# include "libft_bonus.h"

typedef struct s_spec
{
	char	type;
	int		minus;
	int		plus;
	int		space;
	int		hash;
	int		zero;
	int		width;
	int		width_star;
	int		dot;
	int		precision;
	int		precision_star;
}	t_spec;

int		parse_spec(const char *fmt, t_spec *spec);
int		parse_spec_star(va_list *args, t_spec *spec);
int		print_percentage(t_spec spec);
int		print_char(va_list *args, t_spec spec);
int		print_string(va_list *args, t_spec spec);
int		print_signed(va_list *args, t_spec spec);
int		print_unsigned(va_list *args, t_spec spec);
int		print_pointer(va_list *args, t_spec spec);
char	*adjust_format_unsigned(char *s, t_spec spec);
char	*adjust_format_width_space(char *s, int width, int left);
char	*adjust_format_precision_unsigned(char *s, size_t n_digits);

#endif
