/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 15:58:10 by jceia             #+#    #+#             */
/*   Updated: 2021/11/17 21:08:41 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 	Prints a number to the standard output.
 * 
 * @param	n 	the number to be printed.
 */
void	ft_putnbr(int n)
{
	ft_putnbr_fd(n, STDOUT_FILENO);
}
