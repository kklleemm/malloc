/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 14:54:40 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/13 20:06:13 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	header :
 *	| 4 Bytes | 4 Bytes | 4 Bytes | 4 Bytes
 *	| void *next_block  | current |  Flag	(0 = not allocated)
 *						   size
 */

#include "ft_malloc.h"

void 			print_bytes(const void *object, size_t size)
{
	printf("[ ");
	for (size_t i = 0; i < size; i++)
		printf("%02x ", ((const unsigned char *) object)[i] & 0xFF);
	printf("]");
}

void			*set_header(t_tiny *page, size_t size)
{
	void		**header;
	int			*flag;
	int			*ssize;

	header = page->firstblock;
	header[0] = (void *)(header[0] + size + 16);
   	ssize = (int *)(header + 8);
	flag = (int *)(header + 12);
	ssize[0] = (int)size;
	flag[0] = 1337;
//	print_bytes(header[0], 16);
	return ((void *)(header[0] + 16));
}
