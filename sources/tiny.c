/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 12:01:56 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/23 12:41:31 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void				ft_print_tiny(void)
{
	t_tiny			*tiny;

	if (!(tiny = (void *)g_page.tiny_head))
		return ;
	while (tiny)
	{
		ft_putstr("TINY : ");
		ft_atoi_hex_nl(tiny->firstblock);
		while (tiny->firstblock)
		{
			if (tiny->firstblock->size)
			{
				ft_atoi_hex((void *)(tiny->firstblock) + sizeof(t_header));
				ft_putstr(" - ");
				ft_atoi_hex((void *)(tiny->firstblock) +
						tiny->firstblock->size + sizeof(t_header));
				ft_putstr(" : ");
				ft_putnbr(tiny->firstblock->size);
				ft_putstr(" octets        ");
				print_mem((void *)(tiny->firstblock) + sizeof(t_header));
			}
			tiny->firstblock = tiny->firstblock->next;
		}
		tiny = tiny->next;
	}
}

void				*ft_malloc_tiny(size_t size)
{
	void			*ret;
	t_tiny			*page;

	ret = NULL;
	page = NULL;
	if (!g_page.tiny_head)
		g_page.tiny_head = ft_new_tiny();
	page = ft_tiny_find(g_page.tiny_head);
	if (page->totalsize + size + sizeof(t_header) < (TINY_PAGE))
		page->totalsize += size + sizeof(t_header);
	else
	{
		page->next = ft_new_tiny();
		page = page->next;
	}
	ret = set_header(page->firstblock, size);
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

t_tiny				*ft_new_tiny(void)
{
	t_tiny	*new;

	if ((new = mmap(0, sizeof(t_tiny) + 1, FLAGS, -1, 0)) == MAP_FAILED)
		return (ft_overninethousand());
	if ((new->firstblock = mmap(0, TINY_PAGE, FLAGS, -1, 0)) == MAP_FAILED)
		return (ft_overninethousand());
	new->totalsize = 0;
	new->next = NULL;
	return (new);
}
