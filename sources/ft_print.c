/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 12:38:48 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/14 13:47:43 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		ft_print(void)
{
	void	**cpy;
	void	**cpy2;

	cpy = NULL;
	cpy2 = NULL;
	if (g_page.tiny_head)
	{
		cpy = (void*)g_page.tiny_head->firstblock;
		ft_putstr("TINY : ");
		while (g_page.tiny_head)
		{
			ft_atoi_hex_nl(cpy);
			while (get_mem_size(g_page.tiny_head->firstblock))
				g_page.tiny_head->firstblock = *(g_page.tiny_head->firstblock);
			if (g_page.tiny_head->next)
			{
				g_page.tiny_head = g_page.tiny_head->next;
				puts("onemoarpage");
			}
			else
				break ;
		}
	}
	if (g_page.small_head)
	{
		cpy2 = (void*)g_page.small_head->firstblock;
		ft_putstr("SMALL : ");
		while (g_page.small_head)
		{
			ft_atoi_hex_nl(cpy2);
			while (get_mem_size(g_page.small_head->firstblock))
				g_page.small_head->firstblock = *(g_page.small_head->firstblock);
			if (g_page.small_head->next)
			{
				g_page.small_head = g_page.small_head->next;
				puts("onemoarpage");
			}
			else
				break ;
		}
	}
}
