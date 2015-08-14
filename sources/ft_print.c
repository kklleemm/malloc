/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 12:38:48 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/14 23:08:30 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int		check_flag(void **header)
{
	int	*flag;

	flag = (int *)(header + 12);
	return (flag[0]);
}

void		ft_print(void)
{
	void	**cpy;
	void	**cpy2;
	void	*tmp;
	t_tiny	*tiny;

	cpy = NN;
	cpy2 = NN;
	tmp = NN;
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
				ft_atoi_hex_nl((void *)(tiny->firstblock + tiny->size));
			}
			tiny->firstblock = *tiny->firstblock;
		}
		tiny = tiny->next;
	}
}
