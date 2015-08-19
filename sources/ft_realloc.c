/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 18:07:06 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/19 17:36:51 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		*realloc(void *ptr, size_t size)
{
	if (ptr != NULL)
		free (ptr);
	ptr = malloc(size);
	return (ptr);
}

void		*calloc(size_t count, size_t size)
{
	void	*ret;

	ret = NULL;
	ret = malloc(count * size);
	return (ret);
}
