/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 18:15:41 by cdeniau           #+#    #+#             */
/*   Updated: 2015/01/05 13:14:20 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	unsigned int	lens2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	lens2 = ft_strlen(s2);
	if (lens2 < n)
	{
		s1 = ft_memcpy(s1, s2, lens2);
		while (lens2 < n)
		{
			s1[lens2] = '\0';
			lens2++;
		}
	}
	else
		s1 = ft_memcpy(s1, s2, n);
	return (s1);
}
