/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 22:12:08 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/14 23:53:20 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void				ft_print_small(void)
{
	t_tiny			*small;

	if (!g_page.small_head)
		return ;
	small = (void *)g_page.small_head;
	ft_putstr("SMALL : ");
	while (small)
	{
		ft_atoi_hex_nl(small->firstblock);
		while (get_mem_size(small->firstblock))
		{
			if (check_flag(small->firstblock) == 1337)
			{
				ft_atoi_hex((void *)(small->firstblock + 16));
				ft_putstr(" - ");
				ft_atoi_hex((void *)(small->firstblock + small->size));
				ft_putstr(" : ");
				ft_putnbr((int)(get_mem_size(small->firstblock)));
				ft_putstr(" octets        ");
				print_mem((void *)(small->firstblock + 16));
			}
			small->firstblock = *small->firstblock;
		}
		small = small->next;
	}
}

void				*ft_malloc_small(size_t size)
{
	void			*ret;
	t_small			*page;

	ret = NN;
	page = NN;
	if (!g_page.small_head)
	{
		g_page.nb_small = 1;
		g_page.small_head = ft_new_small();
	}
	page = ft_small_find(g_page.small_head, g_page.nb_small);
	if (!(page->size + (int)size + 16 > (SMALL_PAGE)))
		page->size += (int)size + 16;
	else
	{
		page->next = ft_new_small();
		page = page->next;
		g_page.nb_small++;
	}
	ret = set_header(page->firstblock, size);
	return (ret);
}

t_small				*ft_small_find(t_small *page, int nbsmall)
{
	t_small			*cpy;
	int				i;

	i = 0;
	cpy = page;
	while (++i < nbsmall)
		cpy = cpy->next;
	return (cpy);
}

t_small				*ft_new_small(void)
{
	t_small	*new;

	new = mmap(0, sizeof(t_small) + 1, FLAGS, -1, 0);
	new->firstblock = mmap(0, SMALL_PAGE * 16, FLAGS, -1, 0);
	new->next = NN;
	return (new);
}
