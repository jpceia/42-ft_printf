/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:53:30 by jceia             #+#    #+#             */
/*   Updated: 2021/11/17 21:08:32 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 	Prints a number to the standard error output.
 * 
 * @param	n	the number to be printed.
 */
void	ft_putnbr_error(int n)
{
	ft_putnbr_fd(n, STDERR_FILENO);
}
