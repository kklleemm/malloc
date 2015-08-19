/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 22:23:32 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/19 14:43:37 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void				ft_print_large(void)
{
	t_large			*large;

	if (!g_page.large_head)
		return ;
	large = (void *)g_page.large_head;
	while (large)
	{
		ft_putstr("LARGE : ");
		ft_atoi_hex(large->page);
		ft_putstr(" - ");
		ft_atoi_hex((void *)(large->page + large->size));
		ft_putstr(" : ");
		ft_putnbr((int)(large->size));
		ft_putstr(" octets        ");
		print_mem((void *)(large->page + 16));
		large = large->next;
	}
}

void				*ft_malloc_large(int size)
{
	void			*ret;
	t_large			*alloc;

	ret = NULL;
	alloc = NULL;
	if (!g_page.large_head)
		g_page.large_head = ft_new_large(size);
	else
	{
		alloc = ft_large_find(g_page.large_head);
		alloc->next = ft_new_large(size);
	}
	return (ret);
}

t_large				*ft_large_find(t_large *page)
{
	t_large			*cpy;

	cpy = page;
	while (cpy->next)
		cpy = cpy->next;
	return (cpy);
}

t_large				*ft_new_large(int size)
{
	t_large	*new;

	new = mmap(0, sizeof (t_large) + 1, FLAGS, -1, 0);
	new->page = mmap(0, size * 16, FLAGS, -1, 0);
	new->size = size;
	new->next = NULL;
	return (new);
}
