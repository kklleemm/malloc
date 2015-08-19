/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 14:52:26 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/18 20:59:44 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void			free(void *ptr)
{
	t_header	*pouet;

//	printf("%s\n", (char *)ptr);
	pouet = ptr - 16;
//	printf("%i\n", pouet->flg);
	if (pouet->flg == 1337)
		pouet->flg = 0;
	ptr = NULL;
}
