/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 18:14:08 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/17 17:25:37 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_page				g_page;

void				show_alloc_mem(void)
{
	ft_print_tiny();
	ft_print_small();
//	ft_print_large();
}

t_page				*find_page(size_t size)
{
	char			type;
	t_page			*cpy;

	type = get_type(size);
	cpy = g_env.page;
	while (cpy)
	{
		if (cpy->type == type && !cpy->full)
		{
			if ((cpy->totalsize + size + 32) > get_page_size(type))
			{
				cpy->full = 1;
				return (NULL);
			}
			else
			{
				cpy->totalsize += size + 32;
				return (cpy);
			}
		}
		cpy = cpy->next;
	}
	return (NULL);
}

void				*malloc(size_t size)
{
	struct rlimit	rlp;
	t_page			*page;

	page = NULL;
	if (getrlimit(RLIMIT_AS, &rlp) < 0)
		return (NULL);
	if (rlp.rlim_cur < size)
		return (NULL); // perror
	if (size >= SMALL)
		;// large malloc
	else if ((page = find_page(size)) != NULL)
		return (ft_new_malloc(page, get_type(size)));
	page = get_malloc(page, size);
	//
	//
	return (page);
}
