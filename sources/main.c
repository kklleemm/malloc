/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 10:01:19 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/06 10:38:45 by cdeniau          ###   ########.fr       */
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

	puts("cc");
//	if (size <= tiny_size())
	ret = mmap(0, tiny_size(), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0); // ??
	puts("cc");
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
	puts("cc");
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

/*
int			main(int ac, char **av)
{
	int		i;
	int		nb;
	char	c;
	char	*str;

	if (ac != 3)
		ft_nope();
	i = -1;
	nb = atoi(av[2]);
	c = av[1][0];
	str = (char *)mmap(0, nb + 1, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	while (++i < nb)
		str[i] = c;
	str[i] = '\0';
	printf("%s\n", str);
	return (0);
}
*/
