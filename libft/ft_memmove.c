/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:09:24 by jpceia            #+#    #+#             */
/*   Updated: 2021/02/10 01:05:08 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ptr_dest;
	char	*ptr_src;
	char	*holder;
	size_t	index;

	ptr_dest = (char *)dest;
	ptr_src = (char *)src;
	holder = malloc(n);
	if (!holder)
		return (NULL);
	index = 0;
	while (index < n)
	{
		holder[index] = ptr_src[index];
		index++;
	}
	index = 0;
	while (index < n)
	{
		ptr_dest[index] = holder[index];
		index++;
	}
	free(holder);
	return (dest);
}
