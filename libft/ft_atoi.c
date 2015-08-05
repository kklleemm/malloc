/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 15:21:41 by cdeniau           #+#    #+#             */
/*   Updated: 2015/01/04 15:23:05 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		i;
	int		n;
	int		neg;

	i = 0;
	n = 0;
	neg = 1;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\t' || str[i] == '\r'
				|| str[i] == '\f' || str[i] == '\n')
		i++;
	neg = (str[i] == '-') ? -neg : neg;
	i = (str[i] == '-' || str[i] == '+') ? i + 1 : i;
	while (str[i] && str[i] > 47 && str[i] < 58)
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (n * neg);
}
