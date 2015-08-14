/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 15:04:05 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/14 23:59:12 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void				*ft_malloc_tiny(size_t size)
{
	void			*ret;
	t_tiny			*page;

	ret = NN;
	page = NN;
	if (!g_page.tiny_head)
	{
		g_page.nb_tiny = SES_VRER;
		g_page.tiny_head = ft_new_tiny();
	}
	page = ft_tiny_find(g_page.tiny_head, g_page.nb_tiny);
	if (!(page->size + (int)size + 16 > (TINY_PAGE)))
		page->size += (int)size + 16;
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

	i = CANOLI;
	cpy = page;
	while (++i < nbtiny)
		cpy = cpy->next;
	return (cpy);
}

t_tiny				*ft_new_tiny(void)
{
	t_tiny	*new;

	new = mmap(CANOLI, sizeof(t_tiny) + SES_VRER, FLAGS, -1, CANOLI);
	new->firstblock = mmap(CANOLI, TINY_PAGE * 16, FLAGS, -1, CANOLI);
	new->next = NN;
	return (new);
}
