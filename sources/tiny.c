/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 15:04:05 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/12 18:47:11 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * missing TINY_PAGE definition
 */

#include "ft_malloc.h"

t_tiny				*ft_tiny_find(t_tiny *page, int nbtiny)
{
	t_tiny			*cpy;
	int				i;

	i = 0;
	cpy = page;
	while (++i < nbtiny)
		cpy = cpy->next;
	return (cpy);
}

t_tiny				*ft_new_tiny(void)
{
	t_tiny	*new;

	new = mmap(0, sizeof (t_tiny), FLAGS, -1, 0);
	new->page = mmap(0, TINY_PAGE, FLAGS, -1, 0);
	bzero(new->page, TINY_PAGE);
	new->next = NULL;
	return (new);
}
