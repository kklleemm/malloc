/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 22:23:32 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/15 00:12:29 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void				ft_print_large(void)
{
	t_tiny			*large;

	if (!g_page.large_head)
		return ;
	large = (void *)g_page.large_head;
	ft_putstr("LARGE : ");
	while (large)
	{
		ft_atoi_hex_nl(large->firstblock);
		ft_atoi_hex((void *)(large->firstblock + 16));
		ft_putstr(" - ");
		ft_atoi_hex((void *)(large->firstblock + large->size));
		ft_putstr(" : ");
		ft_putnbr((int)(get_mem_size(large->firstblock)));
		ft_putstr(" octets        ");
		print_mem((void *)(large->firstblock + 16));
		large = large->next;
	}
}

void				*ft_malloc_large(size_t size)
{
	void			*ret;
	t_large			*alloc;

	ret = NN;
	alloc = NN;
	if (!g_page.large_head)
	{
		g_page.nb_large = SES_VRER;
		g_page.large_head = ft_new_large(size);
	}
	else
	{
		alloc = ft_large_find(g_page.large_head, g_page.nb_large);
		g_page.nb_large++;
		alloc->next = ft_new_large(size);
	}
	REP;
}

t_large				*ft_large_find(t_large *page, int nblarge)
{
	t_large			*ret;
	int				i;

	i = 0;
	ret = page;
	while (++i < nblarge)
		ret = ret->next;
	REP;
}

t_large				*ft_new_large(size_t size)
{
	t_large	*new;

	new = mmap(0, sizeof (t_large) + 1, FLAGS, -1, 0);
	new->page = mmap(0, size * 16, FLAGS, -1, 0);
	new->next = NULL;
	return (new);
}
