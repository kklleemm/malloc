/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 08:57:53 by cdeniau           #+#    #+#             */
/*   Updated: 2015/01/04 18:13:58 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s1;
	char		*s2;
	int			i;

	if (n == 0 || dest == src)
		return (dest);
	s1 = src;
	s2 = dest;
	i = 0;
	while (n--)
	{
		s2[i] = s1[i];
		i++;
	}
	return (dest);
}
