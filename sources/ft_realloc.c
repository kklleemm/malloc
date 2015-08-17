/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 18:07:06 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/17 20:29:06 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		*ft_realloc(void *ptr, size_t size)
{
	void	*ret;
	void	**tmp;

	ret = NULL;
	tmp = (ptr - 16 * 8);
	if (ptr == NULL)
		ret = malloc(size);
		ret = malloc(size);
		ft_memcpy(ret + 16, ptr, size);
		free(ptr);
	return (ret);
}
