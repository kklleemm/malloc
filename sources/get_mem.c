/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 12:18:21 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/12 18:47:08 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_page				g_page;

void				*ft_malloc_tiny(size_t size)
{
	void			*ret;
	t_tiny			*page;
	t_tiny			*cpy;
	int				i;

	i = -1;
	ret = NULL;
	page = NULL;
	cpy = NULL;
	if (!g_page.tiny_head) // tiny 1st call
	{
		g_page.nb_tiny = 1;
		g_page.tiny_head = ft_new_tiny(); // t_tiny creation
	}
	page = ft_tiny_find(g_page.tiny_head, g_page.nb_tiny); // getting last page
	if ((ret = set_header(page, size)) == NULL)
	{
		cpy = ft_new_tiny(); // t_tiny creation
		g_page.tiny_head->next = cpy;
		g_page.nb_tiny++;
		return (ft_malloc_tiny(size));
	}
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
//	else if (size <= SMALL)
//		ret = ft_malloc_small(size);
//	else
//		ret = ft_malloc_large(size);
	return (ret);
}
