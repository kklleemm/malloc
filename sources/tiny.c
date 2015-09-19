/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 12:01:56 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/17 18:09:47 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

/*void				ft_print_tiny(void)
{
	t_tiny			*tiny;

	if (!g_env.tiny_head)
		return ;
	tiny = (void *)g_env.tiny_head;
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
}*/

char				get_type(size_t size)
{
	if (size < TINY)
		return ('T');
	else if (size < SMALL)
		return ('S');
	else
		return ('L');
}

size_t				get_page_size(size_t size)
{
	if (size < TINY)
		return (TINY_PAGE);
	return (SMALL_PAGE);
}

t_page				*get_malloc(t_page *page, size_t size)
{
	void			*ret;
	t_page			*cpy;
	int				first;

	ret = NULL;
	cpy = page;
	first = 0;
	cpy = ft_find(g_env.page);
	if (cpy->totalsize + size + 16 < (get_page_size(size)))
		cpy->totalsize += size + 16;
	else
	{
		cpy->next = ft_new_malloc(size);
		cpy = cpy->next;
		first = 1;
	}
	cpy = set_header(cpy->firstblock, size, first);
	return (page);
}

t_page				*ft_find(t_page *page)
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

	if ((new = mmap(0, sizeof(t_page), FLAGS, -1, 0)) == MAP_FAILED)
		return (ft_overninethousand());
	if ((new->firstblock = mmap(0, get_page_size(size), \
					FLAGS, -1, 0)) == MAP_FAILED)
		return (ft_overninethousand());
	new->totalsize = size;
	new->next = NULL;
	return (new);
}
