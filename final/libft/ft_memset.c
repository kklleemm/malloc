/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:19:47 by cdeniau           #+#    #+#             */
/*   Updated: 2014/11/17 11:18:45 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*z;

	i = 0;
	if (!(len))
		return (b);
	else
	{
		z = (char *)b;
		while (i < len)
		{
			z[i] = c;
			i++;
		}
		return (b);
	}
}
