/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 10:01:19 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/14 11:09:22 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int		main(int ac, char **av)
{
	char	*sampletext;
	int		i;

	if (ac < 3 || ac > 4)
		ft_putendl("Usage : ./test T|S|L nbmalloc [size]");
	i = -1;
	if (ft_strcmp(av[1], "T") == 0)
	{
		while (++i < ft_atoi(av[2]))
			sampletext = ft_malloc(10);
		if (i % 2 == 1)
			puts(ft_strcpy(sampletext, "AAAAAAAAAA"));
		else
			puts(ft_strcpy(sampletext, "BBBBBBBBBB"));
	}
	else if (ft_strcmp(av[1], "S") == 0)
	{
		while (++i < ft_atoi(av[2]))
			sampletext = ft_malloc(1000);
		puts(ft_strcpy(sampletext, "JE ECRI DAN LE SMALL"));
	}
	/*	else if (ft_strcmp(av[1], "L") == 0)
		while (++i < ft_atoi(av[2]))
			sampletext = ft_strdup4("LEL", ft_atoi(av[3]));
//	i = print_t();
*/	ft_putstr("Total : ");
	ft_putnbr(i);
	ft_putchar(10);
	return (0);
}
