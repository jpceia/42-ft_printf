/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:56:24 by jpceia            #+#    #+#             */
/*   Updated: 2021/11/26 22:40:04 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Returns the size of the largest branch passed as argument.
 * @param	root	the root of the tree.
 * @return	int		the size of the largest branch.
 */
int	btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (1 + ft_imax(
			btree_level_count(root->left),
			btree_level_count(root->right)));
}
