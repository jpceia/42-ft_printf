/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:39:21 by jpceia            #+#    #+#             */
/*   Updated: 2021/11/17 21:06:43 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 	Writes a string to the given file descriptor.
 * 
 * @param	s	the string to be written. 
 * @param	fd	the file descriptor. 
 */
void	ft_putstr_fd(char *s, int fd)
{
	(void)!write(fd, s, ft_strlen(s));
}
