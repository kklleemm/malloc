/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 10:01:19 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/16 14:32:28 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int		main_realloc(void)
{
	char	*sampletext;

	sampletext = ft_strdup("abcdefghij");
	sampletext = ft_realloc(sampletext, 5);
	ft_print_tiny();
	ft_print_small();
	return (0);
}

char	*large_ret(int nb, int size)
{
	char	*ret;

	(void)nb;
	(void)size;
	ret = NULL;
	return (ret);
}

int		main(int ac, char **av)
{
	char	*sampletext;
	int		i;

	if (!(ft_strcmp(av[1], "R")))
		return(main_realloc());
	if (ac < 3 || ac > 4)
		ft_putendl("Usage : ./test T|S|L|R nbmalloc [size]");
	i = -1;
	if (ft_strcmp(av[1], "T") == 0)
		while (++i < ft_atoi(av[2]))
			sampletext = malloc(10);
	else if (ft_strcmp(av[1], "S") == 0)
		while (++i < ft_atoi(av[2]))
			sampletext = malloc(1000);
	else if (ft_strcmp(av[1], "L") == 0)
	{
		while (++i < ft_atoi(av[2]))
			sampletext = malloc(ft_atoi(av[3]));
	}
	ft_print_tiny();
	ft_print_small();
	ft_print_large();
	return (0);
}
