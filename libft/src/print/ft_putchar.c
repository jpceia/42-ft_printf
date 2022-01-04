/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 15:57:48 by jceia             #+#    #+#             */
/*   Updated: 2021/11/17 21:07:12 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 	Prints a character to the standard output.
 * 
 * @param	c	the character to be printed.
 */
void	ft_putchar(char c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
}
