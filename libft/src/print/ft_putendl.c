/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:50:32 by jceia             #+#    #+#             */
/*   Updated: 2021/11/17 21:04:20 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Prints a string, followed by a newline, to the standard output.
 * 
 * @param 	s	the string to be printed.
 */
void	ft_putendl(char *s)
{
	ft_putendl_fd(s, STDOUT_FILENO);
}
