/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fact.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 16:04:59 by cdeniau           #+#    #+#             */
/*   Updated: 2015/01/06 16:33:50 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_fact(int nb)
{
	int		i;
	int		ret;

	i = 0;
	ret = nb;
	if (nb == 1 || nb == 0)
		return (EXIT_SUCCESS);
	if (nb >= 13 || nb < 0)
		return (EXIT_FAILURE);
	while (++i < nb)
		ret *= (nb - i);
	return (ret);
}
