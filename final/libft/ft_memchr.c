/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 18:04:35 by cdeniau           #+#    #+#             */
/*   Updated: 2015/01/05 14:31:52 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str1;
	unsigned int	i;

	str1 = (unsigned char *)s;
	i = 0;
	if (n > 0 && s)
	{
		while (i < n)
		{
			if (str1[i] == (unsigned char)c)
				return ((void *)(i + str1));
			i++;
		}
	}
	return (NULL);
}
