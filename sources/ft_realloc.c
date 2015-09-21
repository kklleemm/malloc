/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 18:07:06 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/21 18:05:03 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		*realloc(void *ptr, size_t size)
{
	void	*ret;

	if (!ptr)
		ret = malloc(size);
	if (!size && ptr)
	{
		free(ptr);
		return (malloc(TINY));
	}
	return (ret);
}

void		*calloc(size_t count, size_t size)
{
	void	*ret;

	ret = NULL;
	ret = malloc(count * size);
	bzero(ret, count * size);
	return (ret);
}
