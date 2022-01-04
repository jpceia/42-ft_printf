/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 15:58:01 by jceia             #+#    #+#             */
/*   Updated: 2021/11/17 21:07:49 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 	Prints a string to the standard output.
 * 
 * @param	s	the string to be printed.
 */
void	ft_putstr(char *s)
{
	ft_putstr_fd(s, STDOUT_FILENO);
}
