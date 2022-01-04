/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:47:33 by jpceia            #+#    #+#             */
/*   Updated: 2022/01/04 22:21:31 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# define PFT_ERR		-1
# define PFT_STOP	 	 0
# define PFT_CONTINUE	 1

# include <stdarg.h>
# include "libft.h"

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
int		append_percentage(t_spec spec, char **out);
int		append_char(char c, t_spec spec, char **out);
int		append_string(char *s, t_spec spec, char **out);
int		append_signed(int nb, t_spec spec, char **out);
int		append_unsigned(unsigned int nb, t_spec spec, char **out);
int		append_pointer(void *ptr, t_spec spec, char **out);
char	*adjust_format_unsigned(char *s, t_spec spec);
char	*adjust_format_width_space(char *s, int width, int left);
char	*adjust_format_precision_unsigned(char *s, size_t n_digits);
char	*ft_straddc(char *s, char c);

#endif

