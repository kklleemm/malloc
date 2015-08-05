/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:44:09 by cdeniau           #+#    #+#             */
/*   Updated: 2015/01/05 14:25:04 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	i;

	i = -1;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	else if (ft_strlen(s1) < ft_strlen(s2))
		return (NULL);
	while (s1[++i + ft_strlen(s2) - 1])
		if (ft_memcmp(s1 + i, s2, ft_strlen(s2)) == 0)
			return ((char *)s1 + i);
	return (NULL);
}
