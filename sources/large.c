/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 16:18:32 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/19 18:45:44 by cdeniau          ###   ########.fr       */
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
		ft_atoi_hex((void *)(large->page) + 24);
		ft_putstr(" - ");
		ft_atoi_hex((void *)(large->page) + large->size + 24);
		ft_putstr(" : ");
		ft_putnbr(large->size);
		ft_putstr(" octets        ");
		print_mem((void *)(large->page) + 24);
		large = large->next;
	}
}

void				*ft_malloc_large(size_t size)
{
	void			*ret;
	t_large			*large;

	ret = NULL;
	large = NULL;
	if (!g_page.large_head)
	{
		g_page.large_head = ft_new_large(size);
		ret = g_page.large_head->page;
	}
	else
	{
		large = ft_large_find(g_page.large_head);
		large->next = ft_new_large(size);
		ret = large->page;
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

t_large				*ft_new_large(size_t size)
{
	t_large	*new;

	if ((new = mmap(0, sizeof(t_large) + 1, FLAGS, -1, 0)) == MAP_FAILED)
		return (ft_overninethousand());
	if ((new->page = mmap(0, mulpagesize(size), FLAGS, -1, 0)) == MAP_FAILED)
		return (ft_overninethousand());
	new->size = size;
	new->next = NULL;
	return (new);
}
