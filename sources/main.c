/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 10:01:19 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/06 17:16:15 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

/*
 * Vous pouvez avoir une variable globale pour gérer vos allocations et une pour le
 * thread-safe.
 */

void		*ft_malloc(size_t size)
{
	void	*ret;

	if (size <= tiny_size())
		ret = mmap(0, tiny_size(), 0x1 | 0x2, ALLOC_FLAGS, -1, 0);
	else if (size <= small_size())
		ret = mmap(0, small_size(), 0x1 | 0x2, ALLOC_FLAGS, -1, 0);
	else if (size <= large_size())
		ret = mmap(0, large_size(), 0x1 | 0x2, ALLOC_FLAGS, -1, 0);
	else
		ft_putendl("OH NO");
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
	if ((str = (char *)ft_malloc(sizeof(*str) * i + 1)) == NULL)
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

	tamer = ft_strdup2("LEL");
	ft_putendl(tamer);
	return (0);
}
