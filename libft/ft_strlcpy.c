/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 13:00:20 by cdeniau           #+#    #+#             */
/*   Updated: 2014/11/17 16:18:58 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(dst);
	if (size > 0)
	{
		while (src && (size_t)i < size)
		{
			dst[len++] = src[i++];
		}
	}
	dst[len] = '\0';
	return (len);
}
