/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 18:07:06 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/22 17:46:17 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void			*getrealloc(size_t size, void *ptr)
{
	void		*cpy;

	cpy = malloc(size);
	cpy = ft_memcpy(cpy, ptr, size);
	return (cpy);
}

int				realloc_checks(void *ptr, char type)
{
	t_header	*header;
	t_large		*large_p;

	if (type != 'L')
	{
		header = (t_header *)ptr - 1;	
		if (header->flg == 1 || header->flg == 1337)
			return (1);
	}
	else
	{
		large_p = g_page.large_head;
		while (large_p)
		{
			if (large_p->page == ptr)
				return (1);
			large_p = large_p->next;
		}
	}
	return (0);
}

char			get_type(size_t size)
{
	if (size < TINY)
		return ('T');
	else if (size < SMALL)
		return ('S');
	else
		return ('L');
}

void			*realloc(void *ptr, size_t size)
{
	void		*ret;

	ret = NULL;
	if (!ptr)
		return (malloc(size));
	if (!size && ptr)
	{
		free(ptr);
		return (malloc(TINY));
	}
	if (!(realloc_checks(ptr, get_type(size))))
		return (NULL);
	ret = getrealloc(size, ptr);
	pthread_mutex_unlock(&g_lock);
	return (ret);
}

void			*calloc(size_t count, size_t size)
{
	void		*ret;

	ret = NULL;
	ret = malloc(count * size);
	bzero(ret, count * size);
	return (ret);
}
