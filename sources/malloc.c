/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 18:14:08 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/17 20:37:45 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_page				g_page;

void				show_alloc_mem(void)
{
	ft_print_tiny();
	ft_print_small();
//	ft_print_large();
}

void				*malloc(size_t size)
{
	void			*ret;
	struct rlimit	rlp;

	ret = NULL;
	if (getrlimit(RLIMIT_AS, &rlp) < 0)
		return (NULL);
	if (size <= TINY)
		ret = ft_malloc_tiny((int)size);
	else if (size <= SMALL)
		ret = ft_malloc_small((int)size);
//	else
//		ret = ft_malloc_large((int)size);
	return (ret);
}
