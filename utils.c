/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:03:44 by jpceia            #+#    #+#             */
/*   Updated: 2021/04/12 20:31:42 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

char	*adjust_format_width_space(char *s, int width, int left)
{
	char	*s1;
	char	*s2;
	int		len;
	int		n_chars;

	n_chars = ft_strlen(s);
	if (width > n_chars)
	{
		s1 = ft_strdup(s);
		len = (int)width - (int)n_chars;
		s2 = malloc(len + 1);
		ft_memset(s2, ' ', len);
		s2[len] = '\0';
		free(s);
		if (left)
			s = ft_strjoin(s1, s2);
		else
			s = ft_strjoin(s2, s1);
		free(s1);
		free(s2);
	}
	return (s);
}
