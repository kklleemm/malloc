/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 14:46:17 by cdeniau           #+#    #+#             */
/*   Updated: 2015/01/06 14:49:24 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_power(long nb, int power)
{
	long	ret;
	int		i;

	ret = nb;
	i = 0;
	if (power < 0 || nb == 0)
		return (0);
	if (power == 0)
		return (1);
	while (++i < power)
		ret *= nb;
	return (ret);
}
