/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:53:54 by jceia             #+#    #+#             */
/*   Updated: 2021/11/17 21:07:24 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 	Prints a character to the standard error output.
 * 
 * @param	c	the character to be printed.
 */
void	ft_putchar_error(char c)
{
	ft_putchar_fd(c, STDERR_FILENO);
}
