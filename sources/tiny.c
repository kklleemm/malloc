/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 15:04:05 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/14 14:09:18 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void				*ft_malloc_tiny(size_t size)
{
	void			*ret;
	t_tiny			*page;
	int				i;

	i = -1;
	ret = NULL;
	page = NULL;
	if (!g_page.tiny_head) // tiny 1st call
	{
		g_page.nb_tiny = 1;
		g_page.tiny_head = ft_new_tiny(); // t_tiny creation
	}
	page = ft_tiny_find(g_page.tiny_head, g_page.nb_tiny); // getting last page
	if (!(page->size + (int)size + 16 > (TINY_PAGE)))
	{
		ret = set_header(page->firstblock, size);
		page->size += (int)size + 16;
	}
	else
	{
		page->next = ft_new_tiny();
		page = page->next;
		ret = set_header(page->firstblock, size);
		g_page.nb_tiny++;
	}
	if (!ret)
		ft_putendl("OH NO");
	return (ret);
}

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

	new = mmap(0, sizeof (t_tiny) + 1, FLAGS, -1, 0);
	new->firstblock = mmap(0, TINY_PAGE * 16, FLAGS, -1, 0);
	new->next = NULL;
	return (new);
}
