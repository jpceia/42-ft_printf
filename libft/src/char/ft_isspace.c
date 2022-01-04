/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 16:01:22 by jpceia            #+#    #+#             */
/*   Updated: 2021/11/17 20:40:13 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 	Checks if a character corresponds to a white-space character.
 * 
 * @param	c	The character to be checked.
 * @return	int	1 if the character is a white-space character, 0 otherwise.
 */
int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}
