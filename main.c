/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 10:01:19 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/15 14:36:30 by cdeniau          ###   ########.fr       */
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
		while (++i < ft_atoi(av[2]))
			sampletext = malloc(10);
	else if (ft_strcmp(av[1], "S") == 0)
		while (++i < ft_atoi(av[2]))
			sampletext = malloc(1000);
	else if (ft_strcmp(av[1], "L") == 0)
		while (++i < ft_atoi(av[2]))
			sampletext = malloc(ft_atoi(av[3]));
	ft_print_tiny();
	ft_print_small();
	ft_print_large();
	return (0);
}
