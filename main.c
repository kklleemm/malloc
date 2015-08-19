/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 10:01:19 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/19 17:36:18 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int		main_realloc(void)
{
	char	*sampletext;

	sampletext = ft_strdup("abcdefghij");
	sampletext = realloc(sampletext, 5);
	ft_print_tiny();
	ft_print_small();
	ft_print_large();
	return (0);
}

int		main_calloc(void)
{
	char	*sampletext;
	
	sampletext = calloc(1337, 5);
	ft_print_tiny();
	ft_print_small();
	ft_print_large();
	return (0);
}


int		main(int ac, char **av)
{
	char	*sampletext;
	int		i;

	if (!(ft_strcmp(av[1], "R")))
		return(main_realloc());
	if (!(ft_strcmp(av[1], "C")))
		return(main_calloc());
	i = -1;
	if (ac != 3)
		ft_putendl("Usage : ./test (R) nbmalloc size");
	else
	{
		while (++i < ft_atoi(av[1]))
		{	
			sampletext = malloc(ft_atoi(av[2]));
			ft_strcpy(sampletext, "bjr a tous");
		}
		free (sampletext);
	}
	show_alloc_mem();
	return (0);
}
