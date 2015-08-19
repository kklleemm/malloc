/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 10:01:19 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/19 19:48:25 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int		main_realloc(void)
{
	char	*sampletext;

	sampletext = ft_strdup("abcdefghij");
	sampletext = realloc(sampletext, 5);
	show_alloc_mem();
	return (0);
}

int		main_calloc(void)
{
	char	*sampletext;
	
	sampletext = calloc(13, 5);
	sampletext = calloc(123, 8);
	sampletext = calloc(12345, 5);
	show_alloc_mem();
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
		ft_putendl("Usage : ./test (R|C) nbmalloc size");
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
