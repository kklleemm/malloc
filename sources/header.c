/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 14:54:40 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/23 12:42:31 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

size_t			mulpagesize(size_t size)
{
	size /= getpagesize();
	size++;
	size *= getpagesize();
	return (size);
}

void			*set_header(void *firstblock, size_t size)
{
	t_header	*cpy;

	cpy = firstblock;
	while (cpy->next)
	{
		if (cpy->flg == 1 && size <= cpy->size)
		{
			cpy->size = size;
			cpy->flg = 1337;
			return ((void *)(cpy) + sizeof(t_header));
		}
		cpy = cpy->next;
	}
	cpy->size = size;
	cpy->next = (char *)(cpy) + sizeof(t_header) + cpy->size;
	cpy->flg = 1337;
	return ((void *)(cpy) + sizeof(t_header));
}
