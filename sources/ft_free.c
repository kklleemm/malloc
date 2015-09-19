/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 14:52:26 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/19 17:33:44 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int				free_page_t(t_tiny *page)
{
	(void)page;
	return (1);
}

int				free_page_s(t_small *page)
{
	(void)page;
	return (1);
}

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
void			free(void *ptr)
{
	t_header	*header;
	t_tiny		*cur_page_t;
	t_small		*cur_page_s;

	pthread_mutex_lock(&g_lock);
	header = (t_header *)ptr - 1;
	if (!header->size)
		return ; // not allocated
	header->flg = 0;
	ptr = NULL;
	if (header->size < TINY)
	{
		cur_page_t = find_ptr_t(header);
		if (check_empty_page_t(cur_page_t))
			if (!(free_page_t(cur_page_t)))
				; // error
	}
	else if (header->size < SMALL)
	{
		cur_page_s = find_ptr_s(header);
		if (check_empty_page_s(cur_page_s))
			if (!(free_page_s(cur_page_s)))
				; // error
	}
//	else
//	{
//		cur_page_s = find_ptr_s(header);
//		if (check_empty_page_s())
//			if (!(free_page_s()))
//				; // error
//	}
	pthread_mutex_unlock(&g_lock);
	(void)cur_page_t;
	(void)cur_page_s;
}
