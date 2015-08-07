/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 14:52:26 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/07 15:00:23 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		ft_free(void *ptr)
{
	int		len;
	int		err;

	len = tiny_size();
	if ((err = munmap(ptr, len)) < 0)
		ft_putendl("PHAIL");
}
