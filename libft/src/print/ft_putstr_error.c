/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:53:04 by jceia             #+#    #+#             */
/*   Updated: 2021/11/17 21:06:52 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 	Prints a string to the standard error output.
 * 
 * @param	s	the string to be printed. 
 */
void	ft_putstr_error(char *s)
{
	ft_putstr_fd(s, STDERR_FILENO);
}
