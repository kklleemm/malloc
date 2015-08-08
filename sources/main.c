/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 10:01:19 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/08 17:23:40 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

/*
 * Vous pouvez avoir une variable globale pour gérer vos allocations et une pour le
 * thread-safe.
 * == protection de la structure partagee pour qu'elle soit utilisee par un seul
 *  thread ???
 */

t_page		g_page;

void		*malloc(size_t size)
{
	short	type;
//	void	*ret;
	if (size <= tiny_size())
		type = 0;
		//ret = mmap(0, tiny_size(), 0x1 | 0x2, ALLOC_FLAGS, -1, 0);
	else if (size <= small_size())
		type = 1;
		//ret = mmap(0, small_size(), 0x1 | 0x2, ALLOC_FLAGS, -1, 0);
	else if (size <= large_size())
		type = 2;
		//ret = mmap(0, large_size(), 0x1 | 0x2, ALLOC_FLAGS, -1, 0);
	else
		type = 3;
	return (get_mem(type));
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
	char	*sampletext;

	sampletext = ft_strdup2("LEL");
/*
	ft_atoi_hex((void *)&sampletext);
	puts("");
	ft_atoi_hex((void *)&sampletext + sizeof sampletext);
	printf("\n%p\n", (void *)&sampletext);
	printf("%p\n", (void *)&sampletext + sizeof sampletext);
	ft_free(sampletext);
	ft_putendl(sampletext);
*/
	return (0);
}
