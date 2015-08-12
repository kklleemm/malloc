/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 14:54:40 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/12 12:58:46 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	header :
 *	| 4 Bytes | 4 Bytes | 4 Bytes
 *	| void *next_bloc   | current size (0 = not allocated)
 */

#include "ft_malloc.h"

void print_bytes(const void *object, size_t size)
{
  size_t i;

  printf("[ ");
  for(i = 0; i < size; i++)
  {
    printf("%02x ", ((const unsigned char *) object)[i] & 0xff);
  }
  printf("]");
}

void			*header(void *page, size_t size)
{
	int			i;
	int			*mem;

	i = 8;
	while (i < TINY_PAGE - (int)size - 12)
	{
		mem = (int *)(page + i);
		if (*mem || *mem == 0)
		{
			mem[0] = (int)size;
			printf("size = %i\n", (int)size);
			print_bytes(page + 8, 4);
			ft_memcpy(mem - i, mem + mem[0], 8);
			return (page + 4);
		}
		i += *mem + 8;
	}
	return (NULL);
}
