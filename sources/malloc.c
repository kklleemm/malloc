/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 18:14:08 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/10 22:19:17 by cdeniau          ###   ########.fr       */
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

void		print(void)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (g_page.tiny_head)
	{
		ft_putstr("TINY : ");
		ft_atoi_hex_nl(g_page.tiny_head->page + i);
		while (++j < g_page.nb_tiny)
		{
			ft_atoi_hex(g_page.tiny_head->page + i);
			ft_putstr(" - ");
			i += g_page.tiny_head->csize;
			ft_atoi_hex(g_page.tiny_head->page + i);
			ft_putstr(" : ");
			ft_putnbr(g_page.tiny_head->csize);
			ft_putendl(" octets");
		}
		g_page.tiny_head = g_page.tiny_head->next;
	}
}

void		*ft_malloc(size_t size)
{
	void	*ret;

	ret = get_mem(size);
	print ();
	return (ret);
}
