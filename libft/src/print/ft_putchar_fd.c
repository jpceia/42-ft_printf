/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:47:38 by jpceia            #+#    #+#             */
/*   Updated: 2021/11/17 21:07:19 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Prints a character to the given file descriptor.
 * 
 * @param	c	the character to be printed.
 * @param	fd	the file descriptor. 
 */
void	ft_putchar_fd(char c, int fd)
{
	(void)!write(fd, &c, 1);
}
