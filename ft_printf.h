/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:52:36 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/04 10:21:40 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "libft_bonus.h"
# include <stdarg.h>

# define PFT_ERR		-1
# define PFT_STOP	 	 0
# define PFT_CONTINUE	 1

typedef struct s_spec
{
	char type;
	char minus;
	char zero;
	char width;
	char width_star;
	char dot;
	char precision;
	char precision_star;
} t_spec;

int		ft_printf(const char *, ...);
int		ft_vprintf(const char *fmt, va_list args);
char	*ft_ptrtoa(void *ptr);
char	*str_arg_char(va_list *args, t_spec *spec);
char	*str_arg_str(va_list *args, t_spec *spec);
void	init_spec(t_spec *spec);
int		parse_spec_loop(char c, t_spec *spec);
int		parse_spec(const char *fmt, t_spec *spec);
char	*str_arg_char(va_list *args, t_spec *spec);
char	*str_arg_str(va_list *args, t_spec *spec);
char	*str_arg_numeric(va_list *args, t_spec *spec);

#endif