/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 14:52:26 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/19 15:51:49 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int				free_page(void *page)
{
	(void)page;
	return (1);
}

int				check_empty_page(void *page)
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

void			*find_ptr(t_header *header)
{
	t_header	*needle;
	void		*haystack;

	if (header->size < TINY)
		haystack = (void *)g_page.tiny_head;
	if (header->size < SMALL)
		haystack = (void *)g_page.small_head;
	else
		;//free large
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
	void		*cur_page;

	pthread_mutex_lock(pthread_mutex_t *mutex);
	header = (t_header *)ptr - 1;
	if (!header->size)
		return ; // not allocated
	header->flg = 0;
	ptr = NULL;
	cur_page = find_ptr(header);
	if (check_empty_page(cur_page))
		if (!(free_page(cur_page)))
			; // print error
	pthread_mutex_unlock(pthread_mutex_t *mutex);
}
