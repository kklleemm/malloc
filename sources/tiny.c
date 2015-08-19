/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 12:01:56 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/19 18:16:03 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void				ft_print_tiny(void)
{
	t_tiny			*tiny;

	if (!g_page.tiny_head)
		return ;
	tiny = (void *)g_page.tiny_head;
	while (tiny)
	{
		ft_putstr("TINY : ");
		ft_atoi_hex_nl(tiny->firstblock);
		while (tiny->firstblock)
		{
			ft_atoi_hex((void *)(tiny->firstblock) + 16);
			ft_putstr(" - ");
			ft_atoi_hex((void *)(tiny->firstblock) +
					tiny->firstblock->size + 16);
			ft_putstr(" : ");
			ft_putnbr(tiny->firstblock->size);
			ft_putstr(" octets        ");
			print_mem((void *)(tiny->firstblock) + 16);
			tiny->firstblock = tiny->firstblock->next;
		}
		tiny = tiny->next;
	}
}

void				*ft_malloc_tiny(int size)
{
	void			*ret;
	t_tiny			*page;
	int				first;

	ret = NULL;
	page = NULL;
	first = 0;
	if (!g_page.tiny_head)
	{
		g_page.tiny_head = ft_new_tiny(size);
		first = 1;
	}
	page = ft_tiny_find(g_page.tiny_head);
	if (page->totalsize + size + 16 < (TINY_PAGE - 32))
		page->totalsize += size + 16;
	else
	{
		page->next = ft_new_tiny(size);
		page = page->next;
		first = 1;
	}
	ret = set_header(page->firstblock, size, first);
	return (ret);
}

t_tiny				*ft_tiny_find(t_tiny *page)
{
	t_tiny			*cpy;

	cpy = page;
	while (cpy->next)
		cpy = cpy->next;
	return (cpy);
}

t_tiny				*ft_new_tiny(int size)
{
	t_tiny	*new;

	if ((new = mmap(0, sizeof(t_tiny) + 1, FLAGS, -1, 0)) == MAP_FAILED)
		return (ft_overninethousand());
	if ((new->firstblock = mmap(0, TINY_PAGE, FLAGS, -1, 0)) == MAP_FAILED)
		return (ft_overninethousand());
	new->totalsize = size;
	new->next = NULL;
	return (new);
}
