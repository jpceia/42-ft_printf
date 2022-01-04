/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:43:30 by jpceia            #+#    #+#             */
/*   Updated: 2021/11/17 20:39:33 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 	Checks if the given character is printable.
 * 
 * @param	c   The character to be checked. 
 * @return	int	1 if the character is printable, 0 otherwise. 
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
