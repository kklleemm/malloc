/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 18:07:06 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/22 16:06:10 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void			*realloc_t(size_t size, void *ptr)
{
	void		*cpy;

	cpy = malloc(size);
	ptr = ft_memcpy(cpy, ptr, size);
	return (cpy);
}

void			*realloc(void *ptr, size_t size)
{
	write (1, "r\n", 2);
	if (!ptr)
		return (malloc(size));
	if (!size && ptr)
	{
		free(ptr);
		return (malloc(TINY));
	}
	if (size < TINY)
		return (realloc_t(size, ptr));
	else if (size < SMALL)
		return (realloc_t(size, ptr));
	else
		return (realloc_t(size, ptr));
}

void			*calloc(size_t count, size_t size)
{
	void		*ret;

	ret = NULL;
	ret = malloc(count * size);
	bzero(ret, count * size);
	return (ret);
}
