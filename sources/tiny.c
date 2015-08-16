/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 12:01:56 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/16 17:04:20 by cdeniau          ###   ########.fr       */
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
		while (get_mem_size(tiny->firstblock))
		{
			if (check_flag(tiny->firstblock) == 1337)
			{
				ft_atoi_hex((void *)(tiny->firstblock + 16));
				ft_putstr(" - ");
				ft_atoi_hex((void *)(tiny->firstblock + tiny->size));
				ft_putstr(" : ");
				ft_putnbr((int)(get_mem_size(tiny->firstblock)));
				ft_putstr(" octets        ");
				print_mem((void *)(tiny->firstblock + 16));
			}
			tiny->firstblock = *tiny->firstblock;
		}
		tiny = tiny->next;
	}
}

void				*ft_malloc_tiny(int size)
{
	void			*ret;
	t_tiny			*page;

	ret = NULL;
	page = NULL;
	if (!g_page.tiny_head)
	{
		g_page.nb_tiny = 1;
		g_page.tiny_head = ft_new_tiny();
	}
	page = ft_tiny_find(g_page.tiny_head, g_page.nb_tiny);
	if (!(page->size + size + 16 > (TINY_PAGE)))
		page->size += size + 16;
	else
	{
		page->next = ft_new_tiny();
		page = page->next;
		g_page.nb_tiny++;
	}
	ret = set_header(page->firstblock, size);
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

	new = mmap(0, sizeof(t_tiny) + 1, FLAGS, -1, 0);
	new->firstblock = mmap(0, TINY_PAGE, FLAGS, -1, 0);
	new->next = NULL;
	return (new);
}
