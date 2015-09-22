/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 18:07:06 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/22 13:49:05 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

size_t			get_max_size(char type)
{
	if (type == 'T')
		return (TINY);
	else if (type == 'S')
		return (SMALL);
	return (0);
}

size_t			totalsize(char type)
{
	t_tiny		*t_cpy;
	t_small		*s_cpy;

	if (type == 'T')
	{
		t_cpy = g_page.tiny_head;
		while (t_cpy->next)
			t_cpy = t_cpy->next;
		return (t_cpy->totalsize);
	}
	else if (type == 'S')
	{
		s_cpy = g_page.small_head;
		while (s_cpy->next)
			s_cpy = s_cpy->next;
		return (s_cpy->totalsize);
	}
	return (0);
}

void			*bigger(size_t size, t_header *header, char type, void *ptr)
{
	void	*cpy;

	if (type != 'L' && header->next == NULL && ((totalsize(type) + size) >
			   	get_max_size(type)))
	{
		header->size = size;
		return (ptr);
	}
	cpy = malloc(size);
	ptr = ft_memcpy(cpy, ptr, header->size);
	return (ptr);
}

void			*smaller(size_t size, void *ptr)
{
	void		*cpy;

	cpy = malloc(size);
	ptr = ft_memcpy(cpy, ptr, size);
	return (ptr);
}

void			*get_realloc(size_t size, char type, void *ptr)
{
	t_header	*header;

	header = (t_header *)ptr - 1;
	// mutex
	if (size > header->size)
		bigger(size, header, type, ptr);
	else if (size < header->size)
		smaller(size, ptr);
	else
		return (ptr);
	return (NULL);
}

void			*realloc(void *ptr, size_t size)
{
	t_tiny		*t_page;
	t_small		*s_page;
	t_large		*l_page;
	void		*ret;

	write (1, "r\n", 2);
	if (!ptr)
		ret = malloc(size);
	if (!size && ptr)
	{
		free(ptr);
		return (malloc(TINY));
	}
	if (size < TINY)
		return (get_realloc(size, 'T', ptr));
	else if (size < SMALL)
		return (get_realloc(size, 'S', ptr));
	else if (size >= SMALL)
		return (get_realloc(size, 'L', ptr));
	(void)t_page;
	(void)s_page;
	(void)l_page;
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
