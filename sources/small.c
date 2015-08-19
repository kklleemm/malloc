/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 15:30:14 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/19 18:15:54 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void				ft_print_small(void)
{
	t_small			*small;

	if (!g_page.small_head)
		return ;
	small = (void *)g_page.small_head;
	while (small)
	{
		ft_putstr("SMALL : ");
		ft_atoi_hex_nl(small->firstblock);
		while (small->firstblock)
		{
			ft_atoi_hex((void *)(small->firstblock) + 16);
			ft_putstr(" - ");
			ft_atoi_hex((void *)(small->firstblock) +
					small->firstblock->size + 16);
			ft_putstr(" : ");
			ft_putnbr(small->firstblock->size);
			ft_putstr(" octets        ");
			print_mem((void *)(small->firstblock) + 16);
			small->firstblock = small->firstblock->next;
		}
		small = small->next;
	}
}

void				*ft_malloc_small(int size)
{
	void			*ret;
	t_small			*page;
	int				first;

	ret = NULL;
	page = NULL;
	first = 0;
	if (!g_page.small_head)
	{
		g_page.small_head = ft_new_small(size);
		first = 1;
	}
	page = ft_small_find(g_page.small_head);
	if (page->totalsize + size + 16 < (SMALL_PAGE - 32))
		page->totalsize += size + 16;
	else
	{
		page->next = ft_new_small(size);
		page = page->next;
		first = 1;
	}
	ret = set_header(page->firstblock, size, first);
	return (ret);
}

t_small				*ft_small_find(t_small *page)
{
	t_small			*cpy;

	cpy = page;
	while (cpy->next)
		cpy = cpy->next;
	return (cpy);
}

t_small				*ft_new_small(int size)
{
	t_small	*new;

	if ((new = mmap(0, sizeof(t_small) + 1, FLAGS, -1, 0)) == MAP_FAILED)
		return (ft_overninethousand());
	if ((new->firstblock = mmap(0, SMALL_PAGE, FLAGS, -1, 0)) == MAP_FAILED)
		return (ft_overninethousand());
	new->totalsize = size;
	new->next = NULL;
	return (new);
}
