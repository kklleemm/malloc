/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 09:46:19 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/06 10:37:41 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

size_t		tiny_size(void)
{
	return ((size_t)getpagesize()); // ce truc renvoie 4096
}

size_t		small_size(void)
{
	return (1337);
}

size_t		large_size(void)
{
	return (1337);
}
