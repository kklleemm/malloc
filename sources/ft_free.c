/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 14:52:26 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/23 12:47:17 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

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

int				check_size(t_header *header)
{
	t_tiny		*cur_page_t;
	t_small		*cur_page_s;

	if (header->size < TINY)
	{
		cur_page_t = find_ptr_t(header);
		cur_page_t->totalsize -= (header->size + 24);
		check_empty_page_t(cur_page_t);
		return (1);
	}
	else if (header->size < SMALL)
	{
		cur_page_s = find_ptr_s(header);
		cur_page_s->totalsize -= (header->size + 24);
		check_empty_page_s(cur_page_s);
		return (1);
	}
	else
		return (0);
}

void			free(void *ptr)
{
	t_header	*header;

	if (ptr == NULL)
		return ;
	header = (t_header *)ptr - 1;
	pthread_mutex_lock(&g_lock);
	if ((header->flg != 1337 && header->flg != 1) || ptr == NULL)
	{
		pthread_mutex_unlock(&g_lock);
		return ;
	}
	header->flg = 1;
	ptr = NULL;
	if (!(check_size(header)))
		free_page(ptr);
	pthread_mutex_unlock(&g_lock);
}
