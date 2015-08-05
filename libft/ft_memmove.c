/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 18:14:22 by cdeniau           #+#    #+#             */
/*   Updated: 2015/01/04 18:14:25 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*str1;
	char		*str2;
	char		*temp;
	size_t		i;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (str1 == NULL || str2 == NULL)
		return (0);
	temp = (char *)malloc(sizeof(*temp) * ft_strlen(str2));
	if (temp == NULL)
		return (NULL);
	temp = ft_strcpy(temp, str2);
	while (i < n)
	{
		str1[i] = temp[i];
		i++;
	}
	return (str1);
}
