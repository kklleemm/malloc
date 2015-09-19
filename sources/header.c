/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 14:54:40 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/19 20:49:47 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	header :
**	| 8 Bytes           | 4 Bytes  | 4bytes | 4 Bytes
**	| void *next_block  | current  | align  |  Flag	(0 = not allocated)
**	                       size
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
	t_header	*cpy;

	cpy = firstblock;
	while (cpy->next && cpy->flg == 1337)
		cpy = cpy->next;
	if (!first)
	{
		cpy->next = (char *)(cpy) + sizeof(t_header) + cpy->size;
		cpy = cpy->next;
	}
	cpy->next = NULL;
	cpy->size = size;
	cpy->flg = 1337;
	return ((void *)(cpy) + sizeof(t_header));
}
