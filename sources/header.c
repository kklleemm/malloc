/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 14:54:40 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/19 11:34:43 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 **	header :
 **	| 4 Bytes | 4 Bytes | 4 Bytes | 4 Bytes
 **	| void *next_block  | current |  Flag	(0 = not allocated)
 **						   size
 */

#include "ft_malloc.h"

int				mulpagesize(int size)
{
	size /= getpagesize();
	size++;
	size *= getpagesize();
	return (size);
}

void			*set_header(void *firstblock, size_t size, int first)
{
	t_header	*truc;

	truc = firstblock;
	while (truc->next)
		truc = truc->next;
	if (!first)
	{
		truc->next = (char *)(truc) + sizeof(t_header) + truc->size;
		truc = truc->next;
	}
	truc->next = NULL;
	truc->size = size;
	truc->flg = 1337;
	return ((void *)(truc) + sizeof(t_header));
}
