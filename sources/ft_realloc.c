/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 18:07:06 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/15 18:56:18 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int			get_mem_size2(void *truc)
{
	int		lel;

	lel = (int)(truc + 8);
	return (lel);
}

void		*ft_realloc(void *ptr, size_t size)
{
	int		size_mem = 0;
	void	*ret;

	ret = NULL;
	int i = 0;
	while (i += 4)
	{
	ft_putnbr(get_mem_size2(ptr - 16 + i));
	ft_putchar(10);
	if (i > 32)
		break ;
	}
	if ((int)size <= size_mem)
		size_mem = (int)size;
//	else
//	{
//		ret = malloc(ptr);
//		return (ret, ptr, size);
//	}
	return (ptr);
}
