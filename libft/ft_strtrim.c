/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 11:45:43 by cdeniau           #+#    #+#             */
/*   Updated: 2015/01/06 11:50:08 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (s == NULL)
		return (0);
	j = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * j + 1);
	ft_bzero(str, j + 1);
	if (str == NULL)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
		i++;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n' || !s[j])
		j--;
	while (i <= j)
		str[k++] = s[i++];
	str[k] = '\0';
	return (str);
}
