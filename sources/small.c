/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 22:12:08 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/13 22:14:41 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_small				*ft_small_find(t_small *page, int nbsmall)
{
	t_small			*cpy;
	int				i;

	i = 0;
	cpy = page;
	while (++i < nbsmall)
		cpy = cpy->next;
	return (cpy);
}

t_small				*ft_new_small(void)
{
	t_small	*new;

	new = mmap(0, sizeof (t_small) + 1, FLAGS, -1, 0);
	new->firstblock = mmap(0, SMALL_PAGE, FLAGS, -1, 0);
	new->next = NULL;
	return (new);
}
