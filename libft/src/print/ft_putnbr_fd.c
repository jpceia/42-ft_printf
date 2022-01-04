/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:39:48 by jpceia            #+#    #+#             */
/*   Updated: 2021/11/17 21:08:37 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 	Prints a number to the given file descriptor.
 * 
 * @param	n	the number to be printed.
 * @param	fd	the file descriptor. 
 */
void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('0' + (n % 10), fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n < -9)
			ft_putnbr_fd(0 - (n / 10), fd);
		ft_putchar_fd('0' - (n % 10), fd);
	}
}
