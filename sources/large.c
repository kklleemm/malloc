/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 22:23:32 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/13 22:29:54 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_large				*ft_large_find(t_large *page, int nblarge)
{
	t_large			*cpy;
	int				i;

	i = 0;
	cpy = page;
	while (++i < nblarge)
		cpy = cpy->next;
	return (cpy);
}

t_large				*ft_new_large(size_t size)
{
	t_large	*new;

	new = mmap(0, sizeof (t_large) + 1, FLAGS, -1, 0);
	new->page = mmap(0, (int)size, FLAGS, -1, 0);
	new->next = NULL;
	return (new);
}
