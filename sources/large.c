/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 16:50:22 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/10 17:45:52 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_large				*ft_large_find(t_large *page)
{
	t_large			*cpy;

	cpy = page;
	while (cpy->next)
		cpy = cpy->next;
	return (cpy);
}

t_large				*ft_new_large(size_t size)
{
	t_large			*new;

	new = mmap(0, sizeof (t_large *), FLAGS, -1, 0);
	new->page = mmap(0, size, FLAGS, -1, 0);
	new->tsize = size;
	new->next = NULL;
	return (new);
}
