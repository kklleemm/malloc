/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 14:54:40 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/15 16:49:06 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int				get_mem_size(void **firstblock)
{
	int			*size_mem;

	size_mem = (int *)(firstblock + 8);
	if (size_mem)
		return (size_mem[0]);
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
	ssize = (int *)(firstblock + 8);
	ssize[0] = size;
	flag = (int *)(firstblock + 12);
	flag[0] = 1337;
	return ((void *)(firstblock + 16));
}
