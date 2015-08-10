/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 09:46:19 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/10 20:16:47 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

size_t		get_page_size(size_t size)
{
	if (size <= TINY)
		return (TINY_PAGE);
	if (size <= SMALL)
		return (SMALL_PAGE);
	return (0);
}
