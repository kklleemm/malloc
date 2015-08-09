/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 19:18:05 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/09 14:59:31 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		ft_add(t_list **list, t_list *new)
{
	new->next = *list;
	*list = new;
}

t_list		*ft_new(int i)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->e = i;
	new->next = NULL;
	return (new);
}
