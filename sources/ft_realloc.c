/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 18:07:06 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/15 20:32:58 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		*ft_realloc(void *ptr, size_t size)
{
	void	*ret;
	void	**tmp;

	ret = NULL;
	tmp = (ptr - 16 * 8);
	if ((int)size <= get_mem_size(tmp))
		modif_mem_size(tmp, size);
//	else
//	{
//		ret = malloc(ptr);
//	}
	return (ptr);
}
