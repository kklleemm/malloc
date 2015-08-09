/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 10:01:19 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/08 19:02:29 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int		main(void)
{
	char	*sampletext;

	sampletext = ft_strdup("LEL");
	puts("debug");
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
