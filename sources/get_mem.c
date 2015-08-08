/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 12:18:21 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/08 18:42:57 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void				*get_mem(short curtype, t_page *page)
{
	void			*ret;
	struct rlimit	rlp;
	int				flag;

	page = NULL; // del
	(void)curtype; // del
	flag = 0;
	if (getrlimit(RLIMIT_AS, &rlp) < 0) // RLIMIT_AS used by mmap
		return	(NULL);
	while (page)
	{
		if (page->next != NULL)
			page = page->next;
		else
		{
			flag = 1;
			break ;
		}
		puts("loop++");
	}
	ft_putnbr(flag);
//	printf("rlp.rlim_cur = %llu\n", rlp.rlim_cur); // value for a 64-bit signed integer 
//	printf("rlp.rlim_max = %llu\n", rlp.rlim_max); // value for a 64-bit signed integer 
	ret = NULL;
	return (ret);
}
