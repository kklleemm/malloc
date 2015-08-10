/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 18:33:29 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/10 22:14:10 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *		First 4 Bytes = Segment part
 *		Last Byte = Offset part.
 */

#include "ft_malloc.h"

void					ft_atoi_hex(void *ptr)
{
	unsigned long long	address;
	char				str[10];
	char				*base;
	int					i;

	ft_memset(str, 0, 10);
	i = 8;
	base = "0123456789ABCDEF";
	address = (unsigned long long)ptr;
	while (address)
	{
		str[i] = base[address % 16];
		address = address / 16;
		i--;
	}
	ft_putstr("0x");
	ft_putstr(str);
}

void					ft_atoi_hex_nl(void *ptr)
{
	unsigned long long	address;
	char				str[10];
	char				*base;
	int					i;

	ft_memset(str, 0, 10);
	i = 8;
	base = "0123456789ABCDEF";
	address = (unsigned long long)ptr;
	while (address)
	{
		str[i] = base[address % 16];
		address = address / 16;
		i--;
	}
	ft_putstr("0x");
	ft_putendl(str);
}
