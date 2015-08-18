/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 12:01:56 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/18 16:29:57 by cdeniau          ###   ########.fr       */
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
			if (tiny->firstblock->flg == 1337)
			{
				ft_atoi_hex((void *)(tiny->firstblock) + 16);
				ft_putstr(" - ");
				ft_atoi_hex((void *)(tiny->firstblock) + tiny->firstblock->size + 16);
				ft_putstr(" : ");
				ft_putnbr(tiny->firstblock->size);
				ft_putstr(" octets        ");
				print_mem((void *)(tiny->firstblock));
			}
			tiny->firstblock = tiny->firstblock->next;
		}
		if (tiny->next)
			tiny = tiny->next;
		else
			break ;
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
		g_page.tiny_head = ft_new_tiny(size);
	}
	page = ft_tiny_find(g_page.tiny_head, g_page.nb_tiny);
	if (!((int)page->totalsize + size + 16 > (TINY_PAGE - 116)))
	{
		//printf("totalsize=%i + %i + 16 : TINY_PAGE=102400\n", page->totalsize, size);
		page->totalsize += size + 16;
	}
	else
	{
		page->next = ft_new_tiny(size);
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

t_tiny				*ft_new_tiny(int size)
{
	t_tiny	*new;

	new = mmap(0, sizeof(t_tiny) + 1, FLAGS, -1, 0);
	new->firstblock = mmap(0, TINY_PAGE, FLAGS, -1, 0);
	new->totalsize = size + 16;
	new->next = NULL;
	return (new);
}
