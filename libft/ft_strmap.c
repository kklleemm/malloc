/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 18:40:59 by cdeniau           #+#    #+#             */
/*   Updated: 2015/01/05 18:43:40 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	int		i;

	if (s && f)
	{
		i = -1;
		s2 = (char *)malloc(sizeof(*s2) * ft_strlen(s));
		if (!s2)
			return (NULL);
		while (s[++i])
			s2[i] = f(s[i]);
		return (s2);
	}
	return (0);
}
