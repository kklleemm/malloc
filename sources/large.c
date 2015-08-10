/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 16:50:22 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/10 20:37:46 by cdeniau          ###   ########.fr       */
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
	t_large			*new;   // allocation at the begining of the page_size()

	new = mmap(0, sizeof (t_large), FLAGS, -1, 0);
	if (new == MAP_FAILED)
		ft_putendl("new = FAIL");
	new->page = mmap(0, size, FLAGS, -1, 0);
	if (new->page == MAP_FAILED)
		ft_putendl("new->page = FAIL");
	new->next = NULL;
	return (new);
}
