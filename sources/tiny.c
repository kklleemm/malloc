/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 12:01:56 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/17 13:48:06 by cdeniau          ###   ########.fr       */
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

char				get_type(size_t size)
{
	if (size < TINY)
		return ('T');
	else if (size < SMALL)
		return ('S');
	else
		return ('L');
}

void				*get_malloc(t_page *page, size_t size)
{
	void			*ret;
	t_page			*cpy;
	char			type;

	type = get_type;
	ret = NULL;
	cpy = NULL;
	if (!g_page.tiny_head)
		g_page.tiny_head = ft_new_malloc(size, type); // init ???
	page = ft_find(g_page.tiny_head);
	if (page->totalsize + size + 16 < (TINY_PAGE - 32))
		page->totalsize += size + 16;
	else
	{
		page->next = ft_new_tiny(size);
		page = page->next;
		first = 1;
	}
	ret = set_header(page->firstblock, size, first);
	return (page);
}

t_page				*ft_find(t_tiny *page)
{
	t_page			*cpy;

	cpy = page;
	while (cpy->next)
		cpy = cpy->next;
	return (cpy);
}

t_page				*ft_new_malloc(size_t size)
{
	t_page			*new;

	if ((new = mmap(0, sizeof(t_tiny) + 1, FLAGS, -1, 0)) == MAP_FAILED)
		return (ft_overninethousand());
	if ((new->firstblock = mmap(0, TINY_PAGE, FLAGS, -1, 0)) == MAP_FAILED)
		return (ft_overninethousand());
	new->totalsize = size;
	new->next = NULL;
	return (new);
}
