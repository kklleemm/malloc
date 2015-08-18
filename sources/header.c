/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 14:54:40 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/18 20:46:50 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 **	header :
 **	| 4 Bytes | 4 Bytes | 4 Bytes | 4 Bytes
 **	| void *next_block  | current |  Flag	(0 = not allocated)
 **						   size
 **/

#include "ft_malloc.h"

void			*set_header(void *firstblock, int size)
{
	t_header	*truc;

	truc = firstblock;
	while (truc->next)
		truc = truc->next;
	truc->next = (void *)(truc) + sizeof(t_header) + truc->size;
	truc = truc->next;
	truc->next = NULL;
	truc->size = size;
	truc->flg = 1337;
	return ((void *)(truc) + sizeof(t_header));
}
