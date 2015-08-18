/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 18:07:06 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/18 18:34:38 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		*ft_realloc(void *ptr, size_t size)
{
	void	*ret;

	ret = NULL;
	if (ptr == NULL)
		ret = malloc(size);
	free (ptr);
	ret = malloc(size);
	return (ret);
}
