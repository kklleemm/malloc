/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 15:04:05 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/10 21:28:21 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * missing TINY_PAGE definition
 */

#include "ft_malloc.h"

void				*ft_tiny_search(t_tiny *tiny_head, size_t size)
{
	tiny_head->tsize += size;
	tiny_head->csize = size;
	return ((void *)tiny_head->page + tiny_head->tsize);
}

t_tiny				*ft_tiny_find(t_tiny *page)
{
	t_tiny			*cpy;

	cpy = page;
	while (cpy->next)
		cpy = cpy->next;
	return (cpy);
}

t_tiny				*ft_new_tiny(size_t size)
{
	t_tiny	*new;

	new = mmap(0, sizeof (t_tiny), FLAGS, -1, 0);
	new->page = mmap(0, TINY_PAGE, FLAGS, -1, 0);
	new->tsize = size;
	new->next = NULL;
	return (new);
}
