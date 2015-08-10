/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 12:18:21 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/10 14:47:41 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_page				g_page;

void				*ft_malloc_tiny(size_t size)
{
	void			*ret;
	t_tiny			*page;
	int				i;

	i = -1;
	ret = NULL;
	if (!g_page.tiny_head) // tiny 1st call
		g_page.tiny_head = ft_new_tiny(size); // t_tiny creation
	page = ft_tiny_find(g_page.tiny_head); // getting last page
	if (page->allocation) // checkin if alloc > 0 (&& < 400)
		ret = ft_tiny_search(page, size);
	else
	{
		page->next = ft_new_tiny(size);
		return (ft_malloc_tiny(size)); // recursive power
	}
	ft_atoi_hex(ret); // DISPLAY DIS ME SEH
	if (!ret)
		ft_putendl("OH NO");
	return (ret);
}

void				*get_mem(short flag, size_t size)
{
	void			*ret;
	struct rlimit	rlp;

	ret = NULL;
	if (!flag)
	{
		flag = 1;
//		page = init_page(size, flag);
	}
	if (getrlimit(RLIMIT_AS, &rlp) < 0) // RLIMIT_AS used by mmap
		return	(NULL);
	if (size < TINY)
		ret = ft_malloc_tiny(size);
//	printf("rlp.rlim_cur = %llu\n", rlp.rlim_cur); // value for a 64-bit signed integer 
//	printf("rlp.rlim_max = %llu\n", rlp.rlim_max); // value for a 64-bit signed integer 
	return (ret);
}
