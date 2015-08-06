/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 13:20:16 by cdeniau           #+#    #+#             */
/*   Updated: 2015/01/14 16:57:25 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	ft_str2(const char *s1, const char *s2, int i, size_t n)
{
	size_t	k;
	size_t	j;

	k = i;
	j = 0;
	while (s2[j] == s1[k] && s1[k] && s2[j] && k < n)
	{
		k++;
		j++;
		if (!s2[j])
			return (1);
	}
	return (0);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s2[i])
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		if (s2[0] == s1[i])
			if (ft_str2(s1, s2, i, n) == 1)
				return ((char *)s1 + i);
		i++;
	}
	return (0);
}
