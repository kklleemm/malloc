/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 17:34:57 by cdeniau           #+#    #+#             */
/*   Updated: 2015/08/06 17:37:34 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

/*
 *
 *  int getrlimit(int resource, struct rlimit *rlim); 
 * 
 * struct rlimit {
 *      rlim_t rlim_cur;  // limite souple
 *  rlim_t rlim_max;  // limite stricte (plafond de rlim_cur)
 * };
 *
 */
