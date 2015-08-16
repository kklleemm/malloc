/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 12:38:48 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/16 12:03:44 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int					check_flag(void **header)
{
	int				*flag;

	flag = (int *)(header + 12);
	return (flag[0]);
}

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
