/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 03:20:23 by jceia             #+#    #+#             */
/*   Updated: 2021/03/29 14:54:19 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strdup(const char *src)
{
	unsigned int index;
	char *dest;

	if (!src)
		return (NULL);
	index = 0;
	while (src[index])
		index++;
	dest = malloc(index + 1);
	if (!dest)
		return (NULL);
	index = 0;
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
