/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 12:18:21 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/09 11:37:06 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int					get_type(size_t size)
{
	if (size <= tiny_size())
		return (TINY);
	else if (size <= small_size())
		return (SMALL);
	else if (size <= large_size())
		return (LARGE);
	else
		return ('\0');
}

void				*get_mem(short flag, size_t size)
{
	char			*ret;
	struct rlimit	rlp;

	(void)size;
	ret = NULL;
	if (!flag)
	{
		flag = 1;
//		page = init_page(size, flag);
	}
	if (getrlimit(RLIMIT_AS, &rlp) < 0) // RLIMIT_AS used by mmap
		return	(NULL);
//	printf("rlp.rlim_cur = %llu\n", rlp.rlim_cur); // value for a 64-bit signed integer 
//	printf("rlp.rlim_max = %llu\n", rlp.rlim_max); // value for a 64-bit signed integer 
	return (ret);
}
