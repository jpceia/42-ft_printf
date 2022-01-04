/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imax.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:49:09 by jpceia            #+#    #+#             */
/*   Updated: 2021/11/17 20:44:26 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Returns the maximum of two integers.
 * 
 * @param	x	the first integer. 
 * @param	y	the second integer. 
 * @return	int the maximum of x and y.
 */
int	ft_imax(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}
