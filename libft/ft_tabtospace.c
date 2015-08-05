/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabtospace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 16:47:24 by cdeniau           #+#    #+#             */
/*   Updated: 2015/05/27 16:53:27 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_tabtospace(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
		i++;
	if (!(tmp = (char *)malloc(sizeof(*str) * i + 1)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			str[i] += 23;
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
