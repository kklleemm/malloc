/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 12:38:48 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/17 20:27:01 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void				print_mem(void *mem)
{
	int				i;
	char			*str;

	i = -1;
	str = (char *)mem;
	while (++i < 16)
	{
		if (str[i] > 33 && str[i] < 127)
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
	}
	ft_putchar(10);
}
