/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 18:14:08 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/12 18:36:07 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

/*
 * Vous pouvez avoir une variable globale pour gérer vos allocations et une pour le
 * thread-safe.
 * == protection de la structure partagee pour qu'elle soit utilisee par un seul
 *  thread ???
 */

t_page		g_page;

int			ft_flag(t_tiny *test)
{
	return (test->page->flag);
}

int			print_t(void)
{
	int		i;

	i = 0;
	ft_putstr("TINY : ");
	ft_atoi_hex_nl(g_page.tiny_head->page);
	while (g_page.tiny_head && i++)
	{
		while (ft_flag(g_page.tiny_head))
		{
			ft_atoi_hex(g_page.tiny_head->page + 12);
			ft_putstr(" - ");
			ft_atoi_hex(g_page.tiny_head->page + (g_page.tiny_head->page->current_size + 12));
			ft_putstr(" : ");
			ft_putnbr(g_page.tiny_head->page->current_size);
			ft_putendl(" octets");
			if (g_page.tiny_head->page->next_block)
				g_page.tiny_head->page = g_page.tiny_head->page->next_block;
		}
		if (g_page.tiny_head->next)
			g_page.tiny_head = g_page.tiny_head->next;
	}
	return (i);
}

void		*ft_malloc(size_t size)
{
	void	*ret;

	ret = get_mem(size);
	return (ret);
}
