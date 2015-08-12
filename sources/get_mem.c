/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 12:18:21 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/12 12:01:35 by cdeniau          ###   ########.fr       */
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
	page = NULL;
	if (!g_page.tiny_head) // tiny 1st call
	{
		g_page.nb_tiny = 1;
		g_page.tiny_head = ft_new_tiny(size); // t_tiny creation
	}
	else
	{
		page = ft_tiny_find(g_page.tiny_head); // getting last page
		page = ft_tiny_append(page, size);
	}
	page = ft_tiny_find(g_page.tiny_head); // getting last page
	ret = ft_tiny_search(page, size);
	if (!ret)
		ft_putendl("OH NO");
	return (ret);
}

void				*ft_malloc_small(size_t size)
{
	void			*ret;
	t_small			*page;
	int				i;

	i = -1;
	ret = NULL;
	if (!g_page.small_head) // 1st call
	{
		g_page.nb_small = 1;
		g_page.small_head = ft_new_small(size); // t_tiny creation
	}
	g_page.nb_small++;
	page = ft_small_find(g_page.small_head); // getting last page
	if (size + page->tsize < SMALL_PAGE) // checkin if alloc > 0 (&& < 400)
		ret = ft_small_search(page, size);
	else
	{
		page->next = ft_new_small(size);
		return (ft_malloc_small(size)); // recursive power
	}
//	ft_atoi_hex(ret); // DISPLAY DIS ME SEH
	if (!ret)
		ft_putendl("OH NO");
	return (ret);
}

void				*ft_malloc_large(size_t size)
{
	void			*ret;
	t_large			*large_page;
	int				i;

	i = -1;
	ret = NULL;
	if (!g_page.large_head) // 1st call
	{
		g_page.nb_large = 1;
		g_page.large_head = ft_new_large(size); // t_large creation
		large_page = g_page.large_head;
	}
	else
	{
		g_page.nb_large++;
		large_page = ft_large_find(g_page.large_head); // getting last page
		large_page->next = ft_new_large(size);
		large_page = large_page->next;
	}
	ret = large_page->page;
//	ft_atoi_hex(ret); // DISPLAY DIS ME SEH
	if (!ret)
		ft_putendl("OH NO");
	return (ret);
}

void				*get_mem(size_t size)
{
	void			*ret;
	struct rlimit	rlp;

	ret = NULL;
	if (getrlimit(RLIMIT_AS, &rlp) < 0) // RLIMIT_AS used by mmap
		return	(NULL);
	if (size <= TINY)
		ret = ft_malloc_tiny(size);
	else if (size <= SMALL)
		ret = ft_malloc_small(size);
	else
		ret = ft_malloc_large(size);
	return (ret);
}
