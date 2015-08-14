/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 22:12:08 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/14 14:13:03 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void				*ft_malloc_small(size_t size)
{
	void			*ret;
	t_small			*page;
	int				i;

	i = -1;
	ret = NULL;
	page = NULL;
	if (!g_page.small_head) // tiny 1st call
	{
		g_page.nb_small = 1;
		g_page.small_head = ft_new_small(); // t_tiny creation
	}
	page = ft_small_find(g_page.small_head, g_page.nb_small); // getting last page
	if (!(page->size + (int)size + 16 > (SMALL_PAGE)))
	{
		ret = set_header(page->firstblock, size);
		page->size += (int)size + 16;
	}
	else
	{
		page->next = ft_new_small();
		page = page->next;
		ret = set_header(page->firstblock, size);
		g_page.nb_small++;
	}
	if (!ret)
		ft_putendl("OH NO");
	return (ret);
}

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
	new->firstblock = mmap(0, SMALL_PAGE * 16, FLAGS, -1, 0);
	new->next = NULL;
	return (new);
}
