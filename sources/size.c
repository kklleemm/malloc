/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 09:46:19 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/10 16:27:58 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

size_t		tiny_size(void)
{
	return (TINY);
}

size_t		small_size(void)
{
	return (SMALL);
}

size_t		large_size(void)
{
	return (204800);
}

size_t		get_page_size(size_t size)
{
	if (size <= TINY)
		return (TINY_PAGE);
	if (size <= SMALL)
		return (SMALL_PAGE);
	if (size <= 204800)
		return (1 * 2048800);
	return (0);
}
