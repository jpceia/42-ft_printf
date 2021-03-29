/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:32:36 by jpceia            #+#    #+#             */
/*   Updated: 2021/02/15 20:00:09 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		index;

	index = 0;
	while (str[index])
		index++;
	while (index >= 0)
	{
		if ((unsigned char)str[index] == (unsigned char)c)
			return (&((char *)str)[index]);
		index--;
	}
	return (0);
}
