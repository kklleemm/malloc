/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 16:19:27 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/10 17:19:02 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void				*ft_small_search(t_small *small_head, size_t size)
{
	small_head->tsize += size;
	return ((void *)small_head->page + small_head->tsize);
}

t_small				*ft_small_find(t_small *page)
{
	t_small			*cpy;

	cpy = page;
	while (cpy->next)
		cpy = cpy->next;
	return (cpy);
}

t_small				*ft_new_small(size_t size)
{
	t_small			*new;

	new = mmap(0, sizeof (t_small *), FLAGS, -1, 0);
	new->page = mmap(0, SMALL_PAGE, FLAGS, -1, 0);
	new->tsize = size;
	new->next = NULL;
	return (new);
}
