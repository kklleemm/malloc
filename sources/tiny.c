/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 15:04:05 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/12 12:59:54 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * missing TINY_PAGE definition
 */

#include "ft_malloc.h"

t_tiny				*ft_tiny_append(t_tiny *page, size_t size)
{
	int				curs;

	curs = 0;
	while (curs < TINY_PAGE)
	{
		printf("%p\n", (void *)page + 0);
		printf("%zu\n", (size_t)page + 7);
		printf("%i\n", (int)page + 11);
		if (page + 7 > 0)
			curs += (size + 16);
		else
			break ;
	}
	return (page);
}

void				*ft_tiny_search(t_tiny *tiny_head, size_t size)
{
	(void)size;
	return ((void *)tiny_head->page);
}

t_tiny				*ft_tiny_find(t_tiny *page)
{
	t_tiny			*cpy;

	cpy = page;
	while (cpy->next)
		cpy = cpy->next;
	return (cpy);
}

t_tiny				*ft_new_tiny(size_t size)
{
	t_tiny	*new;

	new = mmap(0, sizeof (t_tiny), FLAGS, -1, 0);
	new->page = mmap(0, TINY_PAGE, FLAGS, -1, 0);
	new->page = header(new->page, size);
	new->next = NULL;
	return (new);
}
