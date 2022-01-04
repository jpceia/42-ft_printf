/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:53:43 by jceia             #+#    #+#             */
/*   Updated: 2021/11/17 21:09:28 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Prints a string, followed by a newline, to the standard error
 * 			output.
 * 
 * @param	s	the string to be printed.
 */
void	ft_putendl_error(char *s)
{
	ft_putendl_fd(s, STDERR_FILENO);
}
