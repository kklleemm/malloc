/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 18:14:08 by cdeniau           #+#    #+#             */
/*   Updated: 2015/09/22 13:48:19 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_page				g_page;
pthread_mutex_t		g_lock = PTHREAD_MUTEX_INITIALIZER;

void				show_alloc_mem(void)
{
	ft_print_tiny();
	ft_print_small();
	ft_print_large();
}

void				*malloc(size_t size)
{
	void			*ret;
	struct rlimit	rlp;

	ret = NULL;
	if (pthread_mutex_init(&g_lock, NULL) || getrlimit(RLIMIT_AS, &rlp) < 0)
		return (NULL);
	write (1, "m", 1);
	ft_putnbr(size);
	write (1, "\n", 1);
	pthread_mutex_lock(&g_lock);
	if (size < TINY)
		ret = ft_malloc_tiny(size);
	else if (size < SMALL)
		ret = ft_malloc_small(size);
	else
		ret = ft_malloc_large(size);
	pthread_mutex_unlock(&g_lock);
	return (ret);
}
