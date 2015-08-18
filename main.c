/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 10:01:19 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/18 18:14:04 by cdeniau          ###   ########.fr       */
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

int		main(int ac, char **av)
{
	char	*sampletext;
	int		i;

	if (!(ft_strcmp(av[1], "R")))
		return(main_realloc());
	i = -1;
	if (ac == 3)
	{
			while (++i < ft_atoi(av[1]))
				sampletext = malloc(ft_atoi(av[2]));
			ft_strcpy(sampletext, "bjr a tous\n");
	}
	else
		ft_putendl("Usage : ./test (R) nbmalloc size");
	show_alloc_mem();
	return (0);
}
