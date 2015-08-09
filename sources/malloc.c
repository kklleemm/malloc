/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 18:14:08 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/09 11:59:38 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

/*
 * Vous pouvez avoir une variable globale pour gérer vos allocations et une pour le
 * thread-safe.
 * == protection de la structure partagee pour qu'elle soit utilisee par un seul
 *  thread ???
 */

t_page		g_page;

void		*malloc(size_t size)
{
	short	flag;
//	void	*ret;

	if (size <= tiny_size())
		flag = 0;
		//ret = mmap(0, tiny_size(), 0x1 | 0x2, ALLOC_FLAGS, -1, 0);
	else if (size <= small_size())
		flag = 0;
		//ret = mmap(0, small_size(), 0x1 | 0x2, ALLOC_FLAGS, -1, 0);
	else if (size <= large_size())
		flag = 0;
		//ret = mmap(0, large_size(), 0x1 | 0x2, ALLOC_FLAGS, -1, 0);
	else
		flag = 0;
	return (get_mem(flag, size));
}
