/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:47:33 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/04 13:25:38 by jpceia           ###   ########.fr       */
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
	int 	minus;
	int		zero;
	int		width;
	int		width_star;
	int		dot;
	int		precision;
	int		precision_star;
}	t_spec;

void	init_spec(t_spec *spec);
int		parse_spec(const char *fmt, t_spec *spec);
char	*ft_ptrtoa(unsigned long ptr);
char	*str_arg_char(va_list *args, t_spec *spec);
char	*str_arg_str(va_list *args, t_spec *spec);
char	*str_arg_signed(va_list *args, t_spec *spec);
char	*str_arg_unsigned(va_list *args, t_spec *spec);
char	*str_arg_pointer(va_list *args, t_spec *spec);
char	*adjust_format_unsigned(char *s, t_spec *spec);
char	*adjust_format_width_space(char *s, int width, int left);
char	*adjust_format_precision_unsigned(char *s, size_t n_digits);

#endif