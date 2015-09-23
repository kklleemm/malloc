/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 12:28:18 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/23 12:28:59 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int				check_empty_page_t(t_tiny *page)
{
	t_header	*header;
	int			i;

	i = 0;
	if (page)
	{
		header = page->firstblock;
		while (header)
		{
			if (header->flg == 1337)
				i++;
			header = header->next;
		}
	}
	return (i);
}

void			*find_ptr_t(t_header *header)
{
	t_header	*needle;
	t_tiny		*haystack;

	haystack = g_page.tiny_head;
	while (haystack)
	{
		needle = haystack->firstblock;
		while (needle)
		{
			if (needle == header)
				return (haystack);
			needle = needle->next;
		}
		haystack = haystack->next;
	}
	return (NULL);
}

int				check_empty_page_s(t_small *page)
{
	t_header	*header;
	int			i;

	i = 0;
	if (page)
	{
		header = page->firstblock;
		while (header)
		{
			if (header->flg == 1337)
				i++;
			header = header->next;
		}
	}
	return (i);
}

void			*find_ptr_s(t_header *header)
{
	t_header	*needle;
	t_small		*haystack;

	haystack = g_page.small_head;
	while (haystack)
	{
		needle = haystack->firstblock;
		while (needle)
		{
			if (needle == header)
				return (haystack);
			needle = needle->next;
		}
		haystack = haystack->next;
	}
	return (NULL);
}
