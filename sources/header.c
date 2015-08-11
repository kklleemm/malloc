/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 14:54:40 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/11 20:44:59 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	header :
 *	| 4 Bytes | 4 Bytes | 4 Bytes | 4 Bytes |
 *	| void *next_bloc   | current |  flag   |
 *						|  size   | int 1 = allocated
 *						   		  | int 0 = free
 */

#include "ft_malloc.h"

void			*header(void *page, size_t size)
{
	int			flag;

	flag = 1;
	puts ("LEL");
	ft_memcpy(page, page + size + 16, 8);
	puts ("LEL");
	ft_memcpy(page + 8, size, 4);
	puts ("LEL");
	ft_memcpy(page + 12, flag, 4);
	puts ("LEL");
	return (page);
}
