/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 14:54:40 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/12 13:34:40 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	header :
 *	| 4 Bytes | 4 Bytes | 4 Bytes | 4 Bytes
 *	| void *next_bloc   | current |  Flag	(0 = not allocated)
 *						   size
 */

#include "ft_malloc.h"

void 			print_bytes(const void *object, size_t size)
{
	printf("[ ");
	for (size_t i = 0; i < size; i++)
		printf("%02x ", ((const unsigned char *) object)[i] & 0xff);
	printf("]");
}

void			*header(void *page, size_t size)
{
	int			i;
	int			flag;
	int			*mem;

	i = 8;
	flag = 1;
	while (i < TINY_PAGE - (int)size - 12)
	{
		mem = (int *)(page);
		if (*mem || *mem == 0)
		{
			mem[0] = *mem + (int)size;
			mem[8] = (int)size;
			mem[12] = (int)flag;
			printf("size = %i\n", (int)size);
			print_bytes(page, 16);
			return (page + i + 4); // ?
		}
		i += *mem + size + 12;
	}
	return (NULL);
}
