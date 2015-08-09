/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 09:46:19 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/09 11:01:29 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

size_t		tiny_size(void)
{
	return ((size_t)getpagesize()); // ce truc renvoie 4096
}

size_t		small_size(void)
{
	return ((size_t)10240);
}

size_t		large_size(void)
{
	return (204800);
}

size_t		get_page_size(size_t size)
{
	if (size <= 4096)
		return (400 * 512);
	if (size <= 10240)
		return (20 * 10240);
	if (size <= 204800)
		return (1 * 2048800);
	return (0);
}
