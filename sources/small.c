/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 11:35:41 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/23 11:51:19 by cdeniau          ###   ########.fr       */
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
			if (small->firstblock->size >= TINY)
			{
				ft_atoi_hex((void *)(small->firstblock) + sizeof(t_header));
				ft_putstr(" - ");
				ft_atoi_hex((void *)(small->firstblock) +
						small->firstblock->size + sizeof(t_header));
				ft_putstr(" : ");
				ft_putnbr(small->firstblock->size);
				ft_putstr(" octets        ");
				print_mem((void *)(small->firstblock) + sizeof(t_header));
			}
			small->firstblock = small->firstblock->next;
		}
		small = small->next;
	}
}

void				*ft_malloc_small(size_t size)
{
	void			*ret;
	t_small			*page;

	ret = NULL;
	page = NULL;
	if (!g_page.small_head)
		g_page.small_head = ft_new_small();
	page = ft_small_find(g_page.small_head);
	if (page->totalsize + size + sizeof(t_header) < (SMALL_PAGE))
		page->totalsize += size + sizeof(t_header);
	else
	{
		page->next = ft_new_small();
		page = page->next;
	}
	ret = set_header(page->firstblock, size);
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

t_small				*ft_new_small(void)
{
	t_small			*new;

	if ((new = mmap(0, sizeof(t_small) + 1, FLAGS, -1, 0)) == MAP_FAILED)
		return (ft_overninethousand());
	if ((new->firstblock = mmap(0, SMALL_PAGE, FLAGS, -1, 0)) == MAP_FAILED)
		return (ft_overninethousand());
	new->totalsize = 0;
	new->next = NULL;
	return (new);
}
