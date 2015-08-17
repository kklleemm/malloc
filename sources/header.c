/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 14:54:40 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/17 20:34:42 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 **	header :
 **	| 4 Bytes | 4 Bytes | 4 Bytes | 4 Bytes
 **	| void *next_block  | current |  Flag	(0 = not allocated)
 **						   size
 **/

#include "ft_malloc.h"

int				modif_mem_size(void **firstblock, int size)
{
	int 		*size_mem;

	size_mem = (int *)(firstblock) + 8;
	size_mem[0] = size;
	return (size_mem[0]);
}

void			*set_header(void *firstblock, int size)
{
	t_header	*truc;

	truc = firstblock;
	while (truc->next)
		truc = truc->next;
	truc->next = truc + size + 16;
	truc = truc->next;
	truc->next = NULL;
	truc->size = size;
	truc->flg = 1337;
	return ((void *)(firstblock) + 16);
}
