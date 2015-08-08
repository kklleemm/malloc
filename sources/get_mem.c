/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 12:18:21 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/08 14:23:39 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void				*get_mem(size_t size)
{
	void			*ret;
	struct rlimit	rlp;

	if (getrlimit(RLIMIT_CORE, &rlp) < 0)
		return	(NULL);
	printf("%llu\n", rlp.rlim_cur);
	ret = NULL;
	return (ret);
}
