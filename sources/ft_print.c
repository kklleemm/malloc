/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 12:38:48 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/15 19:43:55 by cdeniau          ###   ########.fr       */
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

void				ft_print_tiny(void)
{
	t_tiny			*tiny;

	if (!g_page.tiny_head)
		return ;
	tiny = (void *)g_page.tiny_head;
	ft_putstr("TINY : ");
	while (tiny)
	{
		ft_atoi_hex_nl(tiny->firstblock);
		while (get_mem_size(tiny->firstblock))
		{
			if (check_flag(tiny->firstblock) == 1337)
			{
				ft_atoi_hex((void *)(tiny->firstblock + 16));
				ft_putstr(" - ");
				ft_atoi_hex((void *)(tiny->firstblock + tiny->size));
				ft_putstr(" : ");
				ft_putnbr((int)(tiny->size));
				ft_putstr(" octets        ");
				print_mem((void *)(tiny->firstblock + 16));
			}
			tiny->firstblock = *tiny->firstblock;
		}
		tiny = tiny->next;
	}
}
