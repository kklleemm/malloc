/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 10:01:19 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/06 16:24:04 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

/*
 * Vous pouvez avoir une variable globale pour gérer vos allocations et une pour le
 * thread-safe.
 */

void		*malloc(size_t size)
{
	void	*ret;

	printf("ft_malloc : size='%zu' tiny_size='%zu'\n", size, tiny_size());
	if (size <= tiny_size())
		ret = mmap(0, tiny_size(), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	else if (size <= small_size())
		ret = mmap(0, small_size(), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	else if (size <= large_size())
		ret = mmap(0, large_size(), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	else
		puts("NOPE");
	return (ret);
}

char	*ft_strdup2(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[i])
		i++;
	if ((str = (char *)malloc(sizeof(*str) * i + 1)) == NULL)
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
	char	*tamer;
	int		val;

	tamer = ft_strdup2("TEST");
	printf("FROM %p\n", (void *)&tamer);
	printf("TO %p\n", (void *)&tamer + sizeof(tamer));
	val = (void *)&tamer + sizeof(tamer) - (void *)&tamer;
	printf("TOTAL = %i\n", val);
	print_addr(tamer);
	puts("");
	print_addr(tamer + sizeof(tamer));
	puts("");
	ft_putendl(tamer);
	return (0);
}
