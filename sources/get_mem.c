/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 12:18:21 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/09 12:00:14 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void				*get_mem(short flag, size_t size)
{
	char			*ret;
	struct rlimit	rlp;

	if (!flag)
	{
		flag = 1;
		page = init_page(size, flag);
	}
	if (getrlimit(RLIMIT_AS, &rlp) < 0) // RLIMIT_AS used by mmap
		return	(NULL);
	ret = mmap(0, get_page_size(size), PROT_READ | PROT_WRITE, ALLOC_FLAGS, -1, 0);
	ret[0] = get_type(size);
	while (ret != NULL)
	{
		if (get_type(size) == *mem)
		if (!(ret = page_alloc(ret, size)))
			return NULL;
		
	}
//	printf("rlp.rlim_cur = %llu\n", rlp.rlim_cur); // value for a 64-bit signed integer 
//	printf("rlp.rlim_max = %llu\n", rlp.rlim_max); // value for a 64-bit signed integer 
	return (ret);
}
