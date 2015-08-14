/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 14:54:40 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/14 14:21:09 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 **	header :
 **	| 4 Bytes | 4 Bytes | 4 Bytes | 4 Bytes
 **	| void *next_block  | current |  Flag	(0 = not allocated)
 **						   size
 **/

#include "ft_malloc.h"

void 			print_bytes(const void *object, size_t size)
{
	printf("[ ");
	for (size_t i = 0; i < size; i++)
		printf("%02x ", ((const unsigned char *) object)[i] & 0xFF);
	printf("]");
}

int				get_mem_size(void **firstblock)
{
	if (*firstblock + 8)
		return ((int)firstblock[0]);
	return (0);
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
	ssize = (int *)(header + 8);
	ssize[0] = (int)size;
	flag = (int *)(header + 12);
	flag[0] = 1337;
	return ((void *)(header[0] + 16));
}
