/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 14:54:40 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/15 20:31:17 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 **	header :
 **	| 4 Bytes | 4 Bytes | 4 Bytes | 4 Bytes
 **	| void *next_block  | current |  Flag	(0 = not allocated)
 **						   size
 **/

#include "ft_malloc.h"

int				get_mem_size(void **firstblock)
{
	int 		*size_mem;

	size_mem = (int *)(firstblock + 8);
	return (size_mem[0]);
}

int				modif_mem_size(void **firstblock, int size)
{
	int 		*size_mem;

	size_mem = (int *)(firstblock + 8);
	size_mem[0] = size;
	return (size_mem[0]);
}

void			*set_header(void **firstblock, size_t size)
{
	void		**header;
	int			*flag;
	int			*ssize;

	while (get_mem_size(firstblock))
		firstblock = *firstblock;
	header = (void *)firstblock;
	header[0] = (void *)(header + (int)size + 16);
	ssize = (int *)(firstblock + 8);
	ssize[0] = size;
	flag = (int *)(firstblock + 12);
	flag[0] = 1337;
	return ((void *)(firstblock + 16));
}
