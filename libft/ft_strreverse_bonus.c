/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:02:39 by jceia             #+#    #+#             */
/*   Updated: 2021/04/13 17:29:33 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreverse(char *s)
{
	int		index;
	int		len;
	char	holder;

	index = 0;
	len = ft_strlen(s);
	while (index < len / 2)
	{
		holder = s[index];
		s[index] = s[len - index - 1];
		s[len - index - 1] = holder;
		index++;
	}
	return (s);
}
