/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:50:46 by jpceia            #+#    #+#             */
/*   Updated: 2021/11/17 20:44:43 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Returns the minimum of two integers.
 * 
 * @param	x	the first integer. 
 * @param	y	the second integer. 
 * @return	int the minimum of x and y.
 */
int	ft_imin(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}
