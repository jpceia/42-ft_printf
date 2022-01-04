/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:43:09 by jpceia            #+#    #+#             */
/*   Updated: 2021/11/17 20:39:41 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 	Checks if the given character is an ASCII character.
 * 
 * @param	c	The character to be checked.
 * @return	int	1 if the character is an ASCII character, 0 otherwise. 
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}
