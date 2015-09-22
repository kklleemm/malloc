/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 14:52:26 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/22 16:06:43 by cdeniau          ###   ########.fr       */
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

int				close_chain(int i, t_large *next)
{
	t_large		*cpy;
	int			j;

	j = 0;
	cpy = g_page.large_head;
	while (j < i)
	{
		cpy = cpy->next;
		j++;
	}
	cpy = next;
	return (1);
}

int				free_page(void *ptr)
{
	t_large		*cpy;
	int			i;

	i = 0;
	if (!g_page.large_head)
		return (0);
	cpy = g_page.large_head;
	while (cpy->page)
	{
		if (ptr == cpy->page)
		{
			munmap(ptr, cpy->size);
			return (close_chain(i, cpy->next));
		}
		cpy = cpy->next;
		i++;
	}
	return (1);
}

void			free(void *ptr)
{
	t_header	*header;
	t_tiny		*cur_page_t;
	t_small		*cur_page_s;

	write (1, "f", 1);
	write (1, "\n", 1);
	if (ptr == NULL)
		return ;
	header = (t_header *)ptr - 1;
	pthread_mutex_lock(&g_lock);
	if ((header->flg != 1337 && header->flg != 1) || ptr == NULL)
	{
		pthread_mutex_unlock(&g_lock);
		return ; // not allocated
	}
	header->flg = 1;
	ptr = NULL;
	if (header->size < TINY)
	{
		cur_page_t = find_ptr_t(header);
		cur_page_t->totalsize -= (header->size + 24);
		if (check_empty_page_t(cur_page_t))
			if (!(free_page_t(cur_page_t)))
				return ; // error
	}
	else if (header->size < SMALL)
	{
		cur_page_s = find_ptr_s(header);
		cur_page_s->totalsize -= (header->size + 24);
		if (check_empty_page_s(cur_page_s))
			if (!(free_page_s(cur_page_s)))
				return ; // error
	}
	else
		free_page(ptr);
	pthread_mutex_unlock(&g_lock);
}
