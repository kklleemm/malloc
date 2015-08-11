/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 18:14:08 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/11 20:21:59 by cdeniau          ###   ########.fr       */
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

int			print_t(void)
{
	int		i;
	int		j;

	while (g_page.tiny_head)
	{
		j = -1;
		i = 0;
		ft_putstr("TINY : ");
		ft_atoi_hex_nl(g_page.tiny_head);
		while (++j < g_page.nb_tiny)
		{
			ft_atoi_hex(g_page.tiny_head->page + i);
			ft_putstr(" - ");
//			i += g_page.tiny_head->csize;
			ft_atoi_hex(g_page.tiny_head->page + i);
			ft_putstr(" : ");
//			ft_putnbr(g_page.tiny_head->csize);
			ft_putendl(" octets");
		}
		g_page.tiny_head = g_page.tiny_head->next;
	}
	return (i);
}

int			print_s(void)
{
	int		i;
	int		j;

	while (g_page.small_head)
	{
		j = -1;
		i = 0;
		ft_putstr("SMALL : ");
		ft_atoi_hex_nl(g_page.small_head);
		while (++j < g_page.nb_small)
		{
			ft_atoi_hex(g_page.small_head->page + i);
			ft_putstr(" - ");
			i += g_page.small_head->csize;
			ft_atoi_hex(g_page.small_head->page + i);
			ft_putstr(" : ");
			ft_putnbr(g_page.small_head->csize);
			ft_putendl(" octets");
		}
		g_page.small_head = g_page.small_head->next;
	}
	return (i);
}

int			print_l(void)
{
	int		i;

	while (g_page.large_head)
	{
		i = 0;
		ft_putstr("LARGE : ");
		ft_atoi_hex_nl(g_page.large_head->page);
		g_page.large_head = g_page.large_head->next;
	}
	return (i);
}

void		*ft_malloc(size_t size)
{
	void	*ret;

	ret = get_mem(size);
	return (ret);
}
