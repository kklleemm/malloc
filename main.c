/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 10:01:19 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/10 20:13:09 by cdeniau          ###   ########.fr       */
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

char	*ft_strdup3(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[i])
		i++;
	if (!(str = (char *)ft_malloc(2000)))
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

char	*ft_strdup4(const char *s1, int nb)
{
	char	*str;
	int		i;

	i = 0;
	if (s1 == NULL || nb <= 4096)
		return (NULL);
	while (s1[i])
		i++;
	if (!(str = (char *)ft_malloc(nb)))
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
		{
			sampletext = ft_strdup2("LEL");
			ft_putchar(10);
			printf("malloc=%i : %s\n", i, sampletext);
			//			if (sampletext)
			//				free(sampletext);
		}
	}
	else if (ft_strcmp(av[1], "S") == 0)
	{
		while (++i < ft_atoi(av[2]))
		{
			sampletext = ft_strdup3("LEL");
			ft_putchar(10);
			printf("malloc=%i : %s\n", i, sampletext);
			//			if (sampletext)
			//				free(sampletext);
		}
	}
	else if (ft_strcmp(av[1], "L") == 0)
	{
		while (++i < ft_atoi(av[2]))
		{
			sampletext = ft_strdup4("LEL", ft_atoi(av[3]));
			ft_putchar(10);
			printf("malloc=%i : %s\n", i, sampletext);
			//			if (sampletext)
			//				free(sampletext);
		}
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
