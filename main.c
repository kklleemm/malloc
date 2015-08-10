/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 10:01:19 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/10 14:31:50 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

char	*ft_strdup2(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[i])
		i++;
	if (!(str = (char *)ft_malloc(sizeof(*str) * i + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		main(void)
{
	char	*sampletext;
	int		i;

	i = -1;
	while (++i < 410)
	{
		sampletext = ft_strdup2("LEL");
		ft_putchar(10);
		printf("malloc=%i : %s\n", i, sampletext);
//		if (sampletext)
//			free(sampletext);
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
