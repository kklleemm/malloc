/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 12:38:48 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/15 16:46:51 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int					check_flag(void **header)
{
	int				*flag;

	flag = (int *)(header + 14);
	return (flag[0]);
}

void				print_mem(void *mem)
{
	int				i;
	char			*str;

	i = 0;
	str = (char *)mem;
	while (i++ < 16)
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
	void			**cpy;

	if (!g_page.tiny_head)
		return ;
	tiny = (void *)g_page.tiny_head;
	cpy = tiny->firstblock;
	ft_putstr("TINY : ");
	while (tiny)
	{
		ft_atoi_hex_nl(cpy);
		while (get_mem_size(cpy))
		{
			if (check_flag(cpy) == 1337)
			{
				ft_atoi_hex((void *)(cpy + 16));
				ft_putstr(" - ");
				ft_atoi_hex((void *)(cpy + tiny->size));
				ft_putstr(" : ");
				ft_putnbr((int)(tiny->size));
				ft_putstr(" octets        ");
				print_mem((void *)(cpy + 16));
			}
			cpy = *cpy;
		}
		tiny = tiny->next;
	}
}
