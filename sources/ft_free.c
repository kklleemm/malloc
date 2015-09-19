/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 14:52:26 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/19 12:02:59 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_page			find_ptr(t_header *header)
{
	t_header	*needle;
	void		*haystack;

	if (header->size < TINY)
		haysack = g_page.tiny_head;
	if (header->size < SMALL)
		haysack = g_page.small_head;
	else
		;//free large
	while (haysack)
	{
		needle = haysack->firstblock;
		while (needle)
		{
			if (needle == header)
				return (page);
			needle = needle->next;
		}
		haysack = haysack->next;
	}
	return (NULL);
}

void			free(void *ptr)
{
	t_header	*header;
	t_page		*cur_page;

	header = (t_header *)ptr - 1;
	if (!header->size)
		return ; // not allocated
	header->flg = 0;
	ptr = NULL;
	cur_page = find_ptr(header);
	if (check_empty_page(cur_page))
		if (!(free_page(cur_page)))
			; // print error
}
