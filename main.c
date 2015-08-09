/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 10:01:19 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/09 17:59:03 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int		main(void)
{
	char	*sampletext;
	int		i;

	i = -1;
	while (++i < 200)
	{
		sampletext = ft_strdup2("LEL");
		ft_putchar(10);
		ft_putendl(sampletext);
		if (sampletext)
			free(sampletext);
	}
/*
 * ft_atoi_hex((void *)&sampletext);
 * puts("");
 * ft_atoi_hex((void *)&sampletext + sizeof sampletext);
 * printf("\n%p\n", (void *)&sampletext);
 * printf("%p\n", (void *)&sampletext + sizeof sampletext);
 * ft_free(sampletext);
 * ft_putendl(sampletext);
*/
	return (0);
}
