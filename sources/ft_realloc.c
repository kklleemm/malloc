/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 18:07:06 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/16 14:30:52 by cdeniau          ###   ########.fr       */
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
	if ((int)size <= get_mem_size(tmp))
		modif_mem_size(tmp, size);
	else
	{
		ret = malloc(size);
		ft_memcpy(ret + 16, ptr, size);
		free(ptr);
	}
	return (ret);
}
