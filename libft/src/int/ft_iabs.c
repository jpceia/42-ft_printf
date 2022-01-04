/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 21:24:22 by jceia             #+#    #+#             */
/*   Updated: 2021/11/17 20:43:41 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 	Returns the absolute value of the given integer.
 * 
 * @param	x	the input integer. 
 * @return	int the absolute value of the given integer. 
 */
int	ft_iabs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}
