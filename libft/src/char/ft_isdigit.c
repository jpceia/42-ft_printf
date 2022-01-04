/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:43:34 by jpceia            #+#    #+#             */
/*   Updated: 2021/11/17 20:39:39 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 	Checks if the given character is a digit.
 * 
 * @param	c	The character to be checked.
 * @return	int	1 if the character is a digit, 0 otherwise. 
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
