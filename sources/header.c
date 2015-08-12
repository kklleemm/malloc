/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 14:54:40 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/12 18:47:06 by cdeniau          ###   ########.fr       */
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
		printf("%02x ", ((const unsigned char *) object)[i] & 0xff);
	printf("]");
}

void			*set_header(void *page, size_t size)
{
	t_header	*block;
	int			cflag;

	//printf("size = %zu\n", size);
	cflag = 1;
	block = (t_header *)page;
	while (block->flag == 1)
		block = block->next_block;
	block->next_block = page + sizeof(t_header) + size;
	block->current_size = (int)size;
	block->flag = cflag;
	return (block + sizeof(t_header));
}
